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
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define nl cout<<endl;
const double PI = acos(-1.0);
using namespace std;
void cp()
{
    int n, m;
    cin >> n >> m;
    set<int> alive;
    for(int i = 1; i <= n; i++)
        alive.insert(i);
    vector<int> ans(n + 1);
    for(int i = 0; i < m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        auto it = alive.lower_bound(l);
        vector<int> killed;
        while(it != alive.end() && *it <= r)
        {
            if(*it != x)
                killed.pb(*it);
            it++;
        }
        for(int y : killed)
            ans[y] = x, alive.erase(y);
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin>>t;
    while(t--)
    {
        cp();
    }
    return 0;
}