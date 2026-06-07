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

    for (int s : L)
    {
        cout<<s<<" ";
    }
    cout<<endl;

    int ile = 0;

    for (auto it = L.begin(); it != L.end(); ++it)
    {
        // sprawdzamy, czy ta liczba pojawiła się wcześniej
        if (std::find(L.begin(), it, *it) != it)
            continue; // już była → pomijamy

        int ile = std::count(L.begin(), L.end(), *it);

        cout << "liczba " << *it << " wystepuje " << ile << " razy" << endl;
    }


    return 0;
}
