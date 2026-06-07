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
    std::sort(liczby.begin(), liczby.end(),
              [](int a, int b) {
                  return abs(a) > abs(b);   // UWAGA: > bo sortujemy od największej
              }
              );

    cout<<endl;

    for (auto &s : liczby)
        cout<<s<<" ";

    return 0;
}
