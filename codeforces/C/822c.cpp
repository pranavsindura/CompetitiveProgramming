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
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 2 * 100005;

struct node
{
    int l, r, c;
    node(int x, int y, int z) : l(x), r(y), c(z) {}
    bool operator<(const node &x) const
    {
        return pii(l, r) < pii(x.l, x.r);
    };
};

vector<node> range;
int cost[MAXN];
vector<vector<node>> dur(MAXN);

void cp()
{
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cost[i] = c;
        node t = node(a, b, c);
        range.pb(t);
        dur[b - a + 1].pb(range[i]);
    }

    for(int c = 0; c <= x; c++)
        sort(all(dur[c]));

    ll total = INT_MAX;
    for(int c = 1; c < x; c++)
    {
        if(!sz(dur[x - c]) || !sz(dur[c]))
            continue;
        int min_cost[sz(dur[x - c]) + 1];
        min_cost[sz(dur[x - c])] = INT_MAX;
        for(int i = sz(dur[x - c]) - 1; i >= 0; i--)
        {
            min_cost[i] = min(dur[x - c][i].c, min_cost[i + 1]);
        }
        for(int i = 0; i < sz(dur[c]); i++)
        {
            auto it = lower_bound(all(dur[x - c]), node{dur[c][i].r + 1, dur[c][i].r + 1, 0});
            int ind = it - dur[x - c].begin();
            total = min(total, 1LL * min_cost[ind] + 1LL * dur[c][i].c);
        }
    }
    if(total >= INT_MAX)
        cout << -1;
    else
        cout << total;
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