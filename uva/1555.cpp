#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

void cp()
{
    int n;
    double A;
    while(cin >> n >> A)
    {
        double B = DBL_MAX;
        double lo = 0, hi = 1e9;
        for(int itr = 0; itr < 50; itr++)
        {
            double mid = (lo + hi) / 2;
            vector<double> H(n);
            H[0] = A, H[1] = mid;
            for(int i = 1; i < n - 1; i++)
                H[i + 1] = 2 * (H[i] + 1) - H[i - 1];
            bool ok = true;
            for(double x : H)
                ok &= (x >= 0);
            if(ok)
                B = H.back(), hi = mid;
            else
                lo = mid;
        }
        fix(2);
        cout << B << endl;
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