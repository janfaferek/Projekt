#include <iostream>

using namespace std;


class L
{
public:
    int liczba;
    L operator+(const L &licz)const;
};

L L::operator+(const L &licz)const
{
    L wynik;
    wynik.liczba = liczba + licz.liczba;
    return wynik;
}


int main()
{
    L a;
    L b;
    a.liczba = 5;
    b.liczba = 11;
    L c;
    c = a+b;
    cout<<c.liczba<<endl;
    return 0;
}
