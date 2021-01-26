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
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e7 + 5;
int lp[MAXN];
vector<int> prime;
void init()
{
    lp[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(!lp[i])
            lp[i] = i, prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < 1LL * MAXN; j++)
        {
            lp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0)
                break;
        }
    }
}
map<int, int> cnt;
vector<pair<int, ll>> pref;
void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    for(int x : arr)
    {
        while(x > 1)
        {
            int f = lp[x];
            cnt[f]++;
            while(x % f == 0)
                x /= f;
        }
    }
    for(auto x : cnt)
        pref.pb(x);
    for(int i = 1; i < sz(pref); i++)
        pref[i].ss += pref[i - 1].ss;
    int m;
    cin >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        if(u > pref.back().ff || v < pref.front().ff)
        {
            cout << 0 << endl;
            continue;
        }
        int l = sz(pref) - 1, r = 0;
        int lo = 0, hi = sz(pref) - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(pref[mid].ff >= u)
                l = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        lo = 0, hi = sz(pref) - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(pref[mid].ff <= v)
                r = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        ll sum = pref[r].ss - (l ? pref[l - 1].ss : 0);

        cout << (l <= r ? sum : 0) << endl;
    }

}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    init();
    while(t--)
    {
        cp();
    }
    return 0;
}