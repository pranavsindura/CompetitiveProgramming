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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e4 + 5;

ll f(ll n)
{
    return n * (n - 1) * (n - 2) * (n - 3) / 24;
}

void cp()
{
    int n;
    while(cin >> n)
    {
        vector<int> freq(MAXN), mul(MAXN);
        vector<ll> with_gcd(MAXN);

        for(int i = 0, x; i < n; i++)
            cin >> x, freq[x]++;

        for(int i = 1; i < MAXN; i++)
            for(int j = i; j < MAXN; j += i)
                mul[i] += freq[j];

        ll ans = f(n);
        for(int i = MAXN - 1; i > 1; i--)
        {
            with_gcd[i] += f(mul[i]);
            for(int j = 2; j <= sqrt(i); j++)
            {
                if(i % j == 0)
                {
                    int a = j, b = i / j;
                    with_gcd[a] -= with_gcd[i];
                    if(a != b)
                        with_gcd[b] -= with_gcd[i];
                }
            }
            ans -= with_gcd[i];
        }
        cout << ans << endl;
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