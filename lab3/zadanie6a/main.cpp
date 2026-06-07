#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

int randomInt(int min, int max) {
    static default_random_engine e{static_cast<long unsigned int>(time(0))};
    uniform_int_distribution<int> d{min, max};
    return d(e);
}
int main()
{

    //cout<<"podaj n: "<<endl;
    int n = 5;
    vector<int> liczby(n);
    int i = 0;
    while(i<n)
    {
        liczby[i] = randomInt(-20,20);
        i++;
    }
    //wykorzystanie operatora indeksowania
    for (auto &s : liczby)
        cout<<s<<" ";

    cout<<endl;
    int ile = 0;

    for (int i = 0; i<liczby.size(); i++)
    {
        if (std::find(liczby.begin(), liczby.begin() + i, liczby[i]) != liczby.begin() + i)
            continue;
        ile = count(liczby.begin(), liczby.end(), liczby[i]);
        cout<<"liczba: "<<liczby[i]<<" wystepuje: "<<ile<<" razy"<<endl;
    }


    return 0;
}
