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
const int MAXN = 1e5 + 5;

int a, b;
string s;
/*
	So, DP was overkill
	Just take minimum of cnt[0] * b and a
*/

void cp()
{
    cin >> a >> b >> s;
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < ln(s); i++)
    {
        if(s[i] == '0')
            cnt++;
        else
        {
            if(ans == 0) // explode
                ans += a;
            else if(cnt > 0) // combine these with previous group and explode together, or explode only
                ans += min(cnt * b, a);
            cnt = 0;
        }
    }
    cout << ans << endl;
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