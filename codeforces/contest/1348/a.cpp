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
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);
ll po[40];
vector<ll> two;
void init()
{
    po[0] = 1;
    for(int i = 1; i < 40; i++)
    {
        po[i] = po[i - 1] * 2;
    }
}
int n;
ll total = 0;
ll ans = INT_MAX;
ll solve(int i, vector<int> &sub)
{
    if(i == n)
    {
        if(sz(sub) == n / 2)
        {
            ll sum = 0;
            for(int x : sub)
                sum += 1LL * x;
            ll x = total - sum;
            return abs(total - x);

        }
        else
            return INT_MAX;
    }
    else
    {
        ll res = solve(i + 1, sub);
        sub.pb(two[i]);
        res = min(res, solve(i + 1, sub));
        sub.pop_back();
        return res;
    }
}
void cp()
{
    cin >> n;
    two.clear();
    for(int i = 1; i <= n; i++)
        two.pb(po[i]);
    total = po[n + 1] - 2;
    vector<int> sub;
    // ans = solve(0, sub);
    cout << po[n / 2 + 1] - 2 << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    init();
    while(t--)
    {
        cp();
    }
    return 0;
}