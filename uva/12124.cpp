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

void cp()
{
    int n;
    ll budget;
    cin >> n >> budget;
    string type, name;
    int price, quality;
    map<string, vector<pii>> m;
    for(int i = 0; i < n; i++)
    {
        cin >> type >> name >> price >> quality;
        m[type].pb({price, quality});
    }

    vector<vector<pii>> v;
    for(auto x : m)
        v.pb(x.ss);

    ll best = -1;
    ll lo = 0, hi = 1e9;
    while(lo <= hi)
    {
        ll mid = (lo + hi) >> 1;
        // try to keep quality at least mid
        // pick the smallest price
        ll sum = 0;
        for(int i = 0; i < sz(v); i++)
        {
            ll cheap = INT_MAX;
            for(int j = 0; j < sz(v[i]); j++)
                if(v[i][j].ss >= mid)
                    cheap = min(cheap, 1LL * v[i][j].ff);
            sum += cheap;
        }
        if(sum <= budget)
            best = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << best << endl;
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