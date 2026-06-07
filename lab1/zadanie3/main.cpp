#include <iostream>
#include <cstdint>

using namespace std;

uint64_t factorial (int n)
{
    uint64_t silnia = 1;
    for (int i = 1; i < n+1; i++)
    {
        silnia = silnia*i;
    }
    return silnia;
}

int main()
{
    uint64_t result = factorial(15);
    std::cout << result << std::endl; // wynik: 1307674368000
}
