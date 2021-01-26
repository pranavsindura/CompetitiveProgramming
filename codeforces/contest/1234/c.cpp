#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, f = 0, c = 0;
        cin >> n;
        string r[2];
        cin >> r[0] >> r[1];
        for (int i = 0; i < n; i++)
        {
            if (r[c][i] == '1' || r[c][i] == '2')
            {
                continue;
            }
            else
            {
                if (r[(c + 1) % 2][i] == '1' || r[(c + 1) % 2][i] == '2')
                {
                    f = 1;
                    break;
                }
                else
                {
                    c = (c + 1) % 2;
                }
            }
        }
        if (f || c == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}