#include <iostream>
#include <random>
#include <ctime>
#include<list>
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
    int i = 0;
    list<int> L;
    while(i<n)
    {
        L.push_back(randomInt(-20,20));
        i++;
    }

    //dla list nie mozna uzywac operatora indeksowania
    //for (auto &s : liczby)
       // cout<<s<<" ";

    //mozna inaczej:
    for (int s : L)
    {
        cout<<s<<" ";
    }
    cout<<endl;

    //wykorzystanie iteratora
    for (auto it = L.begin(); it != L.end(); it++)
    {
        cout<<*it<<" ";
    }

    int szukana = 6;
    for (auto it = L.begin(); it != L.end(); )
    {
        if (*it == szukana)
        {
            it = L.erase(it);   // erase zwraca NOWY ważny iterator
            break;                   // jeśli chcesz usunąć tylko pierwsze wystąpienie
        }
        else
        {
            ++it;                    // inkrementujesz TYLKO gdy nie było erase
        }
    }

    return 0;
}
