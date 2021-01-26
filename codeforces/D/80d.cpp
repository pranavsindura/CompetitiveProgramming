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
const int MAXN = 1e6 + 5;

void cp()
{
    double a, b;
    cin >> a >> b;
    double total = a * 2 * b;
    double area = a * b;
    double above = 0.5 * a * a / 4;;
    if(a / 4 >= b)
    {
        // line y = b cuts the triangle into a trapezium
        double extraw = a - 4 * b;
        double extrah = a / 4 - b;
        above -= 0.5 * extraw * extrah;
    }
    double p = (area + above) / total;

    // Corner cases
    // in case of a <= 0 we can pick any +ve b that is half of all b
    if(a <= eps)
        p = 0.5;
    // in case b is 0 then we can pick any a
    if(b <= eps)
        p = 1;

    cout << setprecision(15) << fixed << p << endl;
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