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
const int MAXN = 1e5 + 5;
ll val[MAXN];

void gen(int k)
{
    val[0] = 1;
    for(int i = 1; i < MAXN; i++)
    {
        if(i >= k)
            val[i] += val[i - k];
        val[i] %= mod;
        val[i] += val[i - 1];
        val[i] %= mod;
    }
    for(int i = 1; i < MAXN; i++)
    {
        val[i] = (val[i] % mod + val[i - 1] % mod) % mod;
    }
}

void cp()
{
    int q, k;
    cin >> q >> k;
    gen(k);
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (val[r] % mod - val[l - 1] % mod + mod) % mod << endl;
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