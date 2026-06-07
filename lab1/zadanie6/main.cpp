#include <iostream>

using namespace std;
double pi_leibniz(double st)
{
    double pi = 1.0;
    for(double i = 3.0; 1.0/i > st; i=i+4.0)
    {
        pi = pi - 1.0/i;
        pi = pi + 1.0/(i+2.0);
    }
    pi = 4.0*pi;
    return pi;
}

int main()
{
double stop_at = 0.001;
double pi_approx = pi_leibniz(stop_at);
 cout << pi_approx << endl;
}
