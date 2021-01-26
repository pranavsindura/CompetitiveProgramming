#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    map<pi, vector<pi>> mz;
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mz[{a, b}].pb({c, i});
    }
    vector<pi> ans;
    // First solve those with same (x,y) pair
    map<int, vector<pi>> my;
    for(auto &v : mz)
    {
        sort(all(v.ss));
        for(int i = 0; i < sz(v.ss) - 1; i += 2)
            ans.pb({v.ss[i].ss + 1, v.ss[i + 1].ss + 1});
        // If some remain, solve them as those with same x coordinate, different y coordinate
        if(sz(v.ss) % 2)
            my[v.ff.ff].pb({v.ff.ss, v.ss.back().ss});
    }
    vector<pi> rem;
    for(auto &v : my)
    {
        sort(all(v.ss));
        for(int i = 0; i < sz(v.ss) - 1; i += 2)
            ans.pb({v.ss[i].ss + 1, v.ss[i + 1].ss + 1});
        // If some remain solve them as simple x coordinate, 1D case
        if(sz(v.ss) % 2)
            rem.pb({v.ff, v.ss.back().ss});
    }
    sort(all(rem));
    for(int i = 0; i < sz(rem) - 1; i += 2)
        ans.pb({rem[i].ss + 1, rem[i + 1].ss + 1});
    for(pi x : ans)
        cout << x.ff << " " << x.ss << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}