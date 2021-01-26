#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int m, p, e;
        cin >> m;
        vector<int> earr(n + 2, -1);
        for (int i = 0; i < m; i++)
        {
            // power, endurance
            cin >> p >> e;
            earr[e] = max(earr[e], p);
        }
        for (int i = n; i >= 0; i--)
            earr[i] = max(earr[i], earr[i+1]);

        int pos = 0, endu = 1, ans = 0, maxp;
        while (pos < n)
        {
            if (endu == 1)
                maxp = arr[pos];
            else
                maxp = max(maxp, arr[pos]);
            // cout << maxp << " " << endu << endl;
            if (earr[endu] >= maxp)
            {
                if (endu == 1)
                {
                    ans++;
                    endu++;
                    pos++;
                }
                else
                {
                    endu++;
                    pos++;
                }
            }
            else
            {
                if (endu == 1)
                {
                    ans = -1;
                    break;
                }
                else
                {
                    endu = 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}