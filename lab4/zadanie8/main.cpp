#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    ifstream input_file("tekst.txt");
    if (!input_file.is_open()) {
        cerr << "Nie mogę otworzyć pliku\n";
        return 1;
    }

    regex wzor(R"(\d{3}\s\d{3}\s\d{3})");

    string line;
    while (getline(input_file, line))
    {
        smatch m; //musi byc smatch bo inaczej bedziemy wyswietlac cala linijke
        if (regex_search(line, m, wzor)) {
            cout << m.str() << endl;
        }
    }

    return 0;
}
