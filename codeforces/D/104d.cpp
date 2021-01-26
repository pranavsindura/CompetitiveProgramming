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
const int MAXN = 1e6 + 5;

void cp()
{
    ll n, k;
    int p;
    cin >> n >> k >> p;
    if(k == 0)
    {
        ll x;
        while(p--)
            cin >> x, cout << ".";
    }
    else
    {
        if(n & 1)
            k--, n--;
        if(k == 0)
        {
            // was odd
            ll x;
            while(p--)
            {
                cin >> x;
                cout << (x == n + 1 ? "X" : ".");
            }
        }
        else
        {
            if(k > n / 2)
            {
                // all even pos are X
                // last k-n/2 odd pos are X
                // rest are .
                ll x;
                k -= n / 2;
                while(p--)
                {
                    cin >> x;
                    if(x == n + 1)
                        cout << "X";
                    else if(x % 2 == 0)
                        cout << "X";
                    else if(x >= n - (2 * k - 1))
                        cout << "X";
                    else
                        cout << ".";
                }
            }
            else if(k < n / 2)
            {
                // all odd pos are .
                // last k even pos are X
                // rest are .
                ll x;
                while(p--)
                {
                    cin >> x;
                    if(x == n + 1)
                        cout << "X";
                    else if(x % 2 == 1)
                        cout << ".";
                    else if(x >= n - 2 * (k - 1))
                        cout << "X";
                    else
                        cout << ".";
                }
            }
            else
            {
                // all even pos are X
                // rest .
                ll x;
                while(p--)
                {
                    cin >> x;
                    if(x == n + 1)
                        cout << "X";
                    else if(x % 2 == 1)
                        cout << ".";
                    else
                        cout << "X";
                }
            }
        }
    }
    cout << endl;
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