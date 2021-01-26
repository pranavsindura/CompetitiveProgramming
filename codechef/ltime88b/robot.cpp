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

void cp()
{
    int r, c;
    cin >> r >> c;
    // r is y coord
    // c is x coord
    string ans;
    for(int i = 1; i <= r; i++)
    {
        // goto y coord i
        ans += "U";
        ans += string(c, 'R');
        ans += string(c, 'L');
    }
    ans += string(r, 'D');
    for(int i = 1; i <= 2 * c; i++)
    {
        // goto x coord i
        ans += "R";
        ans += string(r, 'U');
        ans += string(r, 'D');
    }
    ans += string(2 * c, 'L');
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