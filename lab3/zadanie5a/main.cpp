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
    for (auto &s : liczby)
        cout<<s<<" ";

    sort(liczby.begin(), liczby.end());
    //po sortowaniu rosnaco
    cout<<endl;
    for (auto &s : liczby)
        cout<<s<<" ";

    cout<<endl;
    sort(liczby.begin(), liczby.end(), greater<int>());
    //po sortowaniu malejaco
    for (auto &s : liczby)
        cout<<s<<" ";

    return 0;
}
