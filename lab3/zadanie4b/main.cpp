#include <iostream>
#include <random>
#include <ctime>
#include<list>
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

    auto max_it = max_element(L.begin(), L.end());
    cout<<"max: "<<*max_it<<endl;

    auto min_it = min_element(L.begin(), L.end());
    cout<<"min: "<<*min_it<<endl<<endl;


    auto [itMin, itMax] = minmax_element(L.begin(), L.end());
    cout<<"Wykorzystanie minmax_element: "<<endl;
    cout << "Max = " << *itMax << endl;
    cout << "Min = " << *itMin << endl;

    return 0;
}
