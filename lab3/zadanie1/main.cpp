#include <iostream>
#include <random>
#include <ctime>

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

    //wykorzystanie iteratora
    cout<<endl;
    for (auto it = liczby.begin(); it != liczby.end(); it++)
    {
        cout<<*it<<" ";
    }

    int szukana = 6;
    for (auto it = liczby.begin(); it != liczby.end(); )
    {
        if (*it == szukana)
        {
            it = liczby.erase(it);   // erase zwraca NOWY ważny iterator
            break;                   // jeśli chcesz usunąć tylko pierwsze wystąpienie
        }
        else
        {
            ++it;                    // inkrementujesz TYLKO gdy nie było erase
        }
    }

    return 0;
}
