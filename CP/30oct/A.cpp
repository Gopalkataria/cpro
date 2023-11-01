#include <iostream>

using namespace std;

int ispow2(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return ispow2(n / 2);
    else
        return 0;
}

void sol()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            if (!ispow2(i+1))
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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