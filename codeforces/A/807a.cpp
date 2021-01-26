#include <bits/stdc++.h>
#define ll long long int
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
    int n, x, ans = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        if (a[i] != b[i])
        {
            ans = 1;
        }
    }
    if (ans)
    {
        cout << "rated";
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] < a[i])
        {
            ans = -1;
            break;
        }
    }
    if (ans)
        cout << "unrated";
    else
        cout << "maybe";
    return 0;
}
