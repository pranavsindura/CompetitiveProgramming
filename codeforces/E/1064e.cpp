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
    int n;
    cin >> n;
    ll l = 1, r = 1e9;
    string bw;

    cout << "0 1" << endl;
    cout.flush();
    cin >> bw;
    string match = bw;
    n--;

    while(n > 1)
    {
        ll line = (l + r) >> 1;
        // guess (line, 1)
        cout << line << " " << 1 << endl;
        cout.flush();
        cin >> bw;
        if(bw == match) // go right
            l = line + 1;
        else
            r = line - 1;
        n--;
    }
    ll line = (l + r) >> 1;
    ll a, b, c, d;
    a = line, b  = 0, c = line, d = 2;
    if(n == 1)
    {
        // guess (line, 2)
        cout << line << " " << 2 << endl;
        cout.flush();
        cin >> bw;
        if(bw == match)
            a--, c++;
        else
            a++, c--;
    }
    cout << a << " " << b << " " << c << " " << d << endl;
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