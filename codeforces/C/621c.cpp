#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

int multiples_of_p(int p, pi range)
{
    int l = range.ff, r = range.ss;
    return (r / p  - (l - 1) / p);
}

void cp()
{
    int n, p;
    cin >> n >> p;
    vector<pi> range(n);
    for(pi &x : range)
        cin >> x.ff >> x.ss;
    double ans = 0;
    for(int i = 0; i < n; i++)
    {
        // i and (i+1)%n
        int p1 = i, p2 = (i + 1) % n;
        int mul1 = multiples_of_p(p, range[p1]), mul2 = multiples_of_p(p, range[p2]);
        int len1 = range[p1].ss - range[p1].ff + 1;
        int len2 = range[p2].ss - range[p2].ff + 1;
        double prob = 1.0 - ((len1 - mul1 + 0.0) / (len1 * 1.0) * (len2 - mul2 + 0.0) / (len2 * 1.0));
        ans += prob;
    }
    ans = ans * 2000.0;
    cout << setprecision(7) << fixed << ans;
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