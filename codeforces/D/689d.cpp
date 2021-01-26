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
const int MAXN = 2e5 + 5;

int a[MAXN], b[MAXN];
int lg[MAXN];
int st[MAXN][26][2];

int mn(int L, int R)
{
    int j = lg[R - L + 1];
    int minimum = min(st[L][j][0], st[R - (1 << j) + 1][j][0]);
    return minimum;
}

int mx(int L, int R)
{
    int j = lg[R - L + 1];
    int maximum = max(st[L][j][1], st[R - (1 << j) + 1][j][1]);
    return maximum;
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    lg[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lg[i] = lg[i / 2] + 1;

    for (int i = 0; i < n; i++)
        st[i][0][0] = b[i], st[i][0][1] = a[i];

    for (int j = 1; j <= 25; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            st[i][j][0] = min(st[i][j - 1][0], st[i + (1 << (j - 1))][j - 1][0]);
            st[i][j][1] = max(st[i][j - 1][1], st[i + (1 << (j - 1))][j - 1][1]);
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        int l = -1, r = -1;
        // Find L
        int lo = i, hi = n - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            int q = mx(i, mid) - mn(i, mid);
            if(q < 0)
                lo = mid + 1;
            else if(q == 0)
                l = mid, hi = mid - 1;
            else
                hi = mid - 1;
        }

        // Find R
        lo = i, hi = n - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            int q =  mx(i, mid) - mn(i, mid);
            if(q < 0)
                lo = mid + 1;
            else if(q == 0)
                r = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }

        if(~l && ~r)
            ans += r - l + 1;
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