#include <iostream>
#include <vector>

using namespace std;

int binary_search(const vector<double> &vec, double szukana)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (vec[mid] == szukana)
            return mid;

        if (vec[mid] < szukana)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // nie znaleziono
}


int main()
{
    vector<double> wektor = {1.0 , 2.0, 3.0, 4.0, 5.0};
    double liczba = 2.0;

    int wynik = binary_search(wektor, liczba);

    cout << wynik; // wypisze 1
}
