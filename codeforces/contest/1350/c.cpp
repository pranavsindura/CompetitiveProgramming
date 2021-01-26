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
const int MAXN = 200005;
int lp[MAXN];
vector<int> prime;
void init()
{
    lp[1] = 1;
    for (int i = 2; i < MAXN; ++i)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            prime.pb(i);
        }
        for(int j = 0; j < sz(prime) && i * prime[j] < MAXN; j++)
        {
            lp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0)
                break;
        }
    }
}

ll power(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x;
        x = x * x;
        y = y / 2;
    }
    return res;
}

vector<vector<int>> freq(MAXN);
vector<int> total(MAXN, 0);
void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        // cout<<x<<": ";
        map<int, int> f;
        while(x > 1)
        {
            f[lp[x]]++;
            x /= lp[x];
            // cout<<lp[x]<<" ";
        }
        for(auto x : f)
        {
            freq[x.ff].pb(x.ss);
            total[x.ff] ++;
        }
        // cout<<endl;
    }
    ll ans = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(total[i] >= n - 1)
        {
            // cout << i << " ";
            sort(all(freq[i]));
            int mi = 0;
            if(sz(freq[i]) == n - 1)
            {
                mi = freq[i][0];
            }
            else
                mi = freq[i][1];
            ans *= power(i, mi);
        }
    }
    cout << ans;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}