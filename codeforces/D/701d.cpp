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
const int MAXN = 1e6 + 5;

int n, k;
double l, v1, v2;

void cp()
{
    cin >> n >> l >> v1 >> v2 >> k;
    n = (n + k - 1) / k;
    double lo = 0, hi = l / v1;
    double ans = l / v1;

    while(hi - lo > eps)
    {
        double mid = (lo + hi) / 2;
        // each group has to reach in mid time

        double t = 0;
        for(int i = 0; i < n; i++)
        {
            double x = (l - v1 * mid) / (v2 - v1);
            t += x;
            if(i + 1 < n) // bus should come back
            {
                double extra = (v2 * x - v1 * x) / (v1 + v2);
                t += extra;
            }
        }
        if(t <= mid)
            ans = mid, hi = mid;
        else
            lo = mid;
    }
    dblout(10);
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