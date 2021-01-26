#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, f = 0, count, i, j;
        cin >> n;
        ll li[n], ri[n], velocity[n];
        for (i = 0; i < n; i++)
        {
            cin >> li[i] >> ri[i] >> velocity[i];
        }
        for (i = 0; i < n; i++)
        {
            count = 0;
            for (j = 0; j < n; j++)
            {
                if (!(((li[i] < li[j]) && (ri[i] < ri[j])) || ((li[i] > li[j]) && (ri[i] > ri[j]))))
                {
                    if (velocity[i] == velocity[j])
                    {
                        count++;
                    }
                }
                else
                {
                    continue;
                }
            }
            if (count >= 3)
            {
                f = 1;
                break;
            }
        }
        if (!f)
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