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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

void factorise(int n, map<int, int> &freq)
{
    if(n == 0)
        return;
    while(n % 2 == 0)
        freq[2]++, n /= 2;
    for(int i = 3; i <= sqrt(n); i += 2)
        if(n % i == 0)
            freq[i]++, n /= i;
    if(n > 1)
        freq[n]++;
}

void cp()
{
    ll n;
    ll x, m;
    cin >> n >> x >> m;

    bool can = true;

    map<int, int> freqx, freqm;
    factorise(x, freqx);
    factorise(m, freqm);

    for(auto &pf : freqm)
        if(!freqx.count(pf.ff))
            can = false;

    if(can || n <= m)
    {
        ll sum = x % m;
        ll op = 1;
        while(op < n)
        {
            ll rem = x % m;
            rem = (rem * rem) % m;
            if(rem == 0)
                break;
            sum += rem;
            x = rem;
            op++;
        }
        cout << sum << endl;
    }
    else
    {
        // there must be repetitions
        // atmost m?
        x %= m;
        vector<int> last_occur(m, -1);
        vector<int> series(1, x);
        last_occur[x] = 0;
        int rep = -1;
        for(int i = 1; i < m + 5; i++)
        {
            ll rem = (x * x) % m;
            if(~last_occur[rem])
            {
                rep = i - last_occur[rem];
                break;
            }
            else
                series.pb(rem), last_occur[rem] = i;
            x = rem;
        }
        // rep must be > 0
        if(~rep)
        {
            int start = sz(series) - rep;
            n -= start;
            ll mul = n / rep;
            ll extra = n % rep;
            ll sum = 0;
            for(int i = 0; i < start; i++)
                sum += series[i];

            for(int i = start; i < sz(series); i++)
                sum += mul * series[i];
            for(int i = 0; i < extra; i++)
                sum += series[start + i];
            cout << sum << endl;
        }
    }
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