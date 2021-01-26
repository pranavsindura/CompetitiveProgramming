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

array<int, MAXN> arr, pref, minpref_pref, minpref_suff;
int n;

int sum(int l, int r)
{
    if(l <= r)
        return pref[r] - pref[l - 1];
    else
        return 0;
}

void cp()
{
    while(cin >> n && n)
    {
        for(int i = 1; i <= n; i++)
            cin >> arr[i];

        pref[0] = 0;
        for(int i = 1; i <= n; i++)
            pref[i] = arr[i] + pref[i - 1];

        minpref_pref[0] = INT_MAX;
        for(int i = 1; i <= n; i++)
            minpref_pref[i] = min(minpref_pref[i - 1], pref[i]);

        minpref_suff[n + 1] = INT_MAX;
        for(int i = n; i >= 1; i--)
            minpref_suff[i] = min(minpref_suff[i + 1], pref[i]);

        int ans = 0;

        for(int i = 1; i <= n; i++)
        {
            bool ok = true;
            if(minpref_suff[i] - sum(1, i - 1) < 0)
                ok = false;
            if(i - 1 >= 1 && sum(i, n) + minpref_pref[i - 1] < 0)
                ok = false;
            ans += ok;
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