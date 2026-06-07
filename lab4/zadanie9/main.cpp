#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

int main()
{
    map<string, int> word_statistics;
    string word;
    regex tylko_litery("[^A-Za-z]+");

    ifstream input_file("tekst.txt");
    if (!input_file.is_open()) {
        cout << "Nie mogę otworzyć pliku\n";
        return 1;
    }

    while (input_file >> word) {

        // USUWANIE znaków nie będących literami
        word = regex_replace(word, tylko_litery, "");

        transform(word.begin(), word.end(), word.begin(),
                  [](unsigned char c){ return std::tolower(c); });

        // pomijamy puste słowa
        if (word.empty())
            continue;

        word_statistics[word]++;
    }

    // kopiowanie mapy do wektora
    vector<pair<string,int>> kopia;
    copy(word_statistics.begin(), word_statistics.end(), back_inserter(kopia));

    // sortowanie po liczbie wystąpień (malejąco)
    sort(kopia.begin(), kopia.end(),
         [](auto &a, auto &b) {
             return a.second > b.second;
         });

    // wypisanie posortowanych wyników
    cout << "\n--- Posortowane ---\n";
    for (auto &p : kopia)
        cout << p.first << " : " << p.second << endl;

    // zapis do pliku
    ofstream output("zapis.txt");
    if (output.is_open()) {
        for (auto &p : kopia)
            output << p.first << " : " << p.second << endl;
    }

    return 0;
}
