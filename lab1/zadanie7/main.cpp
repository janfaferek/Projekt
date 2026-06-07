#include <iostream>

using namespace std;

void draw_square(int n, bool left_diagonal, bool right_diagonal)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool border = (i == 0 || i == n-1 || j == 0 || j == n-1);
            bool left_d = left_diagonal && (i == j);
            bool right_d = right_diagonal && (i + j == n - 1);

            cout << (border || left_d || right_d ? "#" : " ");
        }
        cout << "\n";
    }
}




int main()
{
    draw_square(7, true, true);
    return 0;
}
