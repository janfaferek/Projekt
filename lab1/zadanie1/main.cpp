#include <iostream>
#include <vector>

using namespace std;

void fill_progressive(vector<int> &param, int n)
{
    for(int i = 0; i< n; i++)
    {
        param[i] = i+1;
    }
}

void print_vector(vector<int> &param)
{
    for(int i = 0; i<param.size(); i++)
    {
        cout<<param[i];
    }
}

int main()
{
    int w;
    cout<<"podaj wielkosc wektora:";
    cin>>w;
    vector<int> vec(w);
    fill_progressive(vec, w);
    print_vector(vec);
    return 0;
}

