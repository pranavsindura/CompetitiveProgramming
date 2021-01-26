#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
using namespace std;

void cp()
{
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> ans(n, INT_MAX);
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            ll t = j - i;
            // y = x + td
            if((y - x) % t == 0)
            {
                ll d = (y - x) / t;
                vector<ll> me(n);
                ll off = -i;
                for(int k = 0; k < n; k++)
                    me[k] = x + (off + k) * d;
                if(me.front() <= 0)
                    continue;
                if(me.back() < ans.back())
                    ans = me;
                else if(me.back() == ans.back())
                    ans = min(ans, me);
            }
        }
    }
    for(ll x : ans)
        cout << x << " ";
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}