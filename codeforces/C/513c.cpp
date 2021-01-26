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

ld len(ll l, ll r)
{
    return 1.0 * max(0LL, r - l + 1);
}

void cp()
{
    int n;
    cin >> n;
    vector<pi> arr(n);
    for(pi &x : arr)
        cin >> x.ff >> x.ss;

    ld ans = 0;
    dblout(10);
    for(int val = 10005; val >= 1; val--)
    {
        ld all = 1;
        for(int i = 0; i < n; i++) // <= v
            all *= len(arr[i].ff, min(val, arr[i].ss)) / len(arr[i].ff, arr[i].ss);

        ld none = 1;
        for(int i = 0; i < n; i++) // < v
            none *= len(arr[i].ff, min(val - 1, arr[i].ss)) / len(arr[i].ff, arr[i].ss);

        ld exactly1 = 0;
        for(int i = 0; i < n; i++)
        {
            ld me = (val >= arr[i].ff && val <= arr[i].ss) / len(arr[i].ff, arr[i].ss); // == v
            for(int j = 0; j < n; j++)
                if(i != j)
                    me *= len(arr[j].ff, min(val - 1, arr[j].ss)) / len(arr[j].ff, arr[j].ss); // < v
            exactly1 += me;
        }

        ld atleast2 = all - none - exactly1;
        ans += val * atleast2;

        ld greater = 0;
        for(int i = 0; i < n; i++)
        {
            // > v
            ld me = len(max(val + 1, arr[i].ff), arr[i].ss) / len(arr[i].ff, arr[i].ss);
            ld tot = 1;
            ld nox = 1;
            // atleast 1 v from rest
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    tot *= len(arr[j].ff, min(val, arr[j].ss)) / len(arr[j].ff, arr[j].ss);
                    nox *= len(arr[j].ff, min(val - 1, arr[j].ss)) / len(arr[j].ff, arr[j].ss);
                }
            }
            greater += me * (tot - nox);
        }

        ans += val * greater;
    }
    cout << ans << endl;
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