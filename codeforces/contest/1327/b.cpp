#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pii> edge;
        for(int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;
            for(int j = 0; j < m; j++)
            {
                int k;
                cin >> k;
                edge.pb(mp(i, k));
            }
        }
        sort(all(edge));
        int count = 0;
        vector<bool> dau(n + 1, false), vis(n + 1, false);
        for(pii x : edge)
        {
            if(!dau[x.ff] && !vis[x.ss])
            {
                count++;
                dau[x.ff] = true;
                vis[x.ss] = true;
            }
        }
        if(count == n)
        {
            cout << "OPTIMAL\n";
            continue;
        }
        int leftk, leftd;
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                leftk = i;
                break;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(!dau[i])
            {
                leftd = i;
                break;
            }
        }
        cout << "IMPROVE\n";
        cout << leftd << " " << leftk << endl;
    }
    return 0;
}