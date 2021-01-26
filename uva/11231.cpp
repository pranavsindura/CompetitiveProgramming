#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    while(n && m)
    {
        if (c == 0)
        {
            cout << ((n - 7) * (m - 7)) / 2 << endl;
        }
        else
        {
            cout << ((n - 7) * (m - 7) + 1) / 2 << endl;
        }
        cin >> n >> m >> c;
    }
    return 0;
}