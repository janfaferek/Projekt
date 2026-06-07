#include <iostream>

using namespace std;

enum class Color {
    White,
    Black,
    Red,
    Green,
    Blue,
};

enum kolor
{
    slon,
    pies,
    kot
};

int main()
{
    Color c;
    c = Color::Red;
    if (c == Color::Black) {
        std::cout << "Color is black\n";
    } else if (c == Color::White) {
        std::cout << "Color is white\n";
    }

    kolor k;
    k = pies;
    cout<<k<<endl;

}
