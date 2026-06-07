#include <iostream>
#include <cstdint>
using namespace std;

uint64_t factorial_r (int n)
{

    if (n == 0)
        return 1;
    return n * factorial_r(n-1);
}

int main()
{
    uint64_t result = factorial_r(15);
    std::cout << result << std::endl;
    return 0;
}
