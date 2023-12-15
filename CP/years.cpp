#include <iostream>

using namespace std;

bool special(int n)
{
    int n4 = n % 10;
    int n3 = (n / 10) % 10;
    int n2 = (n / 100) % 10;
    int n1 = (n / 1000) % 10;
    if (n1 != n2 && n1 != n3 && n1 != n4 && n2 != n3 && n2 != n4 && n3 != n4)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n, k;
    cin >> n;
    k = n + 1;
    while (!special(k))
    {
        k++;
    }

    cout << k << endl;
    return 0;
}
