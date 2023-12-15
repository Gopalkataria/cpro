#include <iostream>
using namespace std;
#define _s << " " <<

int main()
{

    long unsigned int t;
    cin >> t  ; 
    while (t--)
    {

        long unsigned int n, k;
        cin >> n >> k;
        long unsigned int m = n - k;
        if (m & 1 || k > n)
        {
            cout << "NO" << endl;
            continue;
        }
        m /= 2;
        // cout _s k _s m;

        if (k >= m && k > 2)
        {
            cout << "NO" << endl;
            continue;
        }

        // cout << m _s k _s endl ;
        if (m >= k * (k - 1) / 2 || k == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
