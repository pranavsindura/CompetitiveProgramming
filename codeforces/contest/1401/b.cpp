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
    int a0, a1, a2;
    int b0, b1, b2;
    cin >> a0 >> a1 >> a2 >> b0 >> b1 >> b2;
    int sum = 0;
    if(a2 < b1)
    {
        sum += a2 * 2;
        if(b2 > a0)
            sum -= (b2 - a0) * 2;
    }
    else
    {
        sum += b1 * 2;
        a2 -= b1;
        if(b2 > a0 + a2)
            sum -= (b2 - (a0 + a2)) * 2;
    }
    cout << sum << endl;
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