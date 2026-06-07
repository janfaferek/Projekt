#include <iostream>
#include <cstdint>
using namespace std;

bool is_prime(int n)
{
    if (n < 2) return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void print_primes_in_range(int d, int g)
{
    for (int i = d; i <= g; i++)
    {
        if (is_prime(i))
            cout << i << " ";
    }
}

int main()
{
    int d, g;
    cout << "podaj zakres dol: ";
    cin >> d;
    cout << "podaj zakres gora: ";
    cin >> g;

    print_primes_in_range(d, g);

    return 0;
}

