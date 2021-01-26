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
const double eps = 1e-8;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, l;
    cin >> n >> l;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    double lo = 0, hi = 2e9;
    double ans = 0;

    while(hi - lo > 10 * eps)
    {
        double mid = (lo + hi) / 2;
        double x = 0;
        double t = mid;
        int pos = 0;
        double speed = 1;
        while(t > eps && pos < n)
        {
            double dist = arr[pos] - x;
            double need = dist / speed;
            double have = min(t, need);
            t -= have;
            x += have * speed;
            pos++;
            speed++;
        }
        if(t > eps)
            x += t * speed;

        double y = l;
        t = mid;
        pos = n - 1;
        speed = 1;
        while(t > eps && pos >= 0)
        {
            double dist = y - arr[pos];
            double need = dist / speed;
            double have = min(t, need);
            t -= have;
            y -= have * speed;
            pos--;
            speed++;
        }

        if(t > eps)
            y -= t * speed;

        if(x > y)
            hi = mid;
        else
            ans = lo = mid;
    }
    dblout(10);
    cout << ans + eps << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}