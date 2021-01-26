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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<int> ver, hor;
    ver.pb(0);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ver.pb(x);
    }
    ver.pb((int)1e9);
    for(int i = 0; i < m; i++)
    {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if(x1 == 1)
            hor.pb(x2);
    }
    sort(all(ver));
    sort(all(hor));
    int pos = 0;
    int mn = INT_MAX;
    for(int i = 0; i < sz(ver) - 1; i++)
    {
        while(pos < sz(hor) && hor[pos] < ver[i + 1])
            pos++;
        // cout << i + sz(hor) - pos << endl;
        mn = min(mn, i + sz(hor) - pos);
    }
    cout << mn;
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