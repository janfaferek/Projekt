#include <iostream>
#include <vector>
using namespace std;

vector<double> bubble_sort(vector<double> &liczby)
{
    double temp;
    int rozmiar = liczby.size();
    while (rozmiar > 0)
    {
        for(int i =0 ; i<rozmiar - 1; i++)
        {
            if(liczby[i] > liczby[i+1])
            {
                temp = liczby[i];
                liczby[i] = liczby[i+1];
                liczby[i+1] = temp;
            }
        }
        rozmiar--;
    }
    return liczby;
}
int main()
{
    vector<double> vec = {2.0, 2.5, 1.5, 4.6, 5.0, 2.2};
    bubble_sort(vec);
    for (auto &s : vec)
        cout<<s<<endl;
    return 0;
}
