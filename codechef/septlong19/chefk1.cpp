#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, sol = 0, flag = 0, temp;
        cin >> n >> m;
        temp = (n * (n + 1)) / 2;
        if (m < (n - 1) || m > temp)
        {
            sol = -1;
        }
        else
        {
            if (m == 0)
            {
                sol = 0;
            }
            else if (m == 1)
            {
                sol = 1;
            }
            else
            {
                if (m <= n + 1)
                {
                    sol = 2;
                }
                else if (m <= 2 * n)
                {
                    sol = 3;
                }
                else
                {
                    m = m - (2 * n);
                    while (m > 0)
                    {
                        sol++;
                        m = m - (n / 2);
                        if (n & 1 == 1)
                        {
                            flag++;
                        }
                        if (flag == 2)
                        {
                            m--;
                            flag = 0;
                        }
                    }
                    sol += 3;
                }
            }
        }
        cout << sol << endl;
    }
    return 0;
}
