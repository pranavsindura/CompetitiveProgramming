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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

vector<int> ans;

void solve(int n, int mul)
{
    if(n == 0)
        return;
    if(n == 3)
    {
        ans.pb(mul);
        ans.pb(mul);
        ans.pb(mul * 3);
        return;
    }
    else
    {
        int odd = (n + 1) / 2;
        for(int i = 0; i < odd; i++)
            ans.pb(mul);
        solve(n - odd, mul * 2);
    }

}

void cp()
{
    int n;
    cin >> n;
    solve(n, 1);
    for(int x : ans)
        cout << x << " ";
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