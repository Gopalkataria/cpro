#include <iostream>

using namespace std;

void sol()
{
    int N;
    cin >> N;
    for (int x = 1; x <= N; x ++)
    {
        for (int y = 0; y < N; y ++)
        {
            if (((x | y) * (x ^ y)) == N)
            {
                cout << x << " " << y << "\n";
                return;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        sol();
    }
}