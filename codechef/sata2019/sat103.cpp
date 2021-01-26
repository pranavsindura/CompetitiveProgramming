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
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<bool> edge(n + 1, false);
        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            edge[a] = true;
            edge[b] = true;
        }
        int first = -1;
        for(int i = 1; i <= n; i++)
        {
            if(edge[i] == true)
            {
                first = i;
                break;
            }
        }
        if(first == -1)
        {
            cout<<0<<endl;
            continue;
        }
        ll cost = 0;
        for(int i=1;i<=n;i++)
        {
            if(edge[i] == false)
            {
                cost += first*i*1LL;
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}