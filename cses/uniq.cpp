#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> uniqueElements;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (find(uniqueElements.begin(), uniqueElements.end(), temp) == uniqueElements.end())
        {
            uniqueElements.push_back(temp);
        }
    }

    int uniqueCount = uniqueElements.size();
    cout << uniqueCount << endl;

    return 0;
}
