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

pi combine(int x, int y)
{
    if(x && y)
    {
        int sg_x = x / abs(x);
        int sg_y = y / abs(y);
        x = abs(x), y = abs(y);
        int g = __gcd(x, y);
        x /= g, y /= g;
        if(sg_x == sg_y)
            return {x, y};
        else
            return {-x, y};
    }
    else if(x)
    {
        return {1, 0};
    }
    else if(y)
    {
        return {0, 1};
    }
    else
    {
        return {0, 0};
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--)
    {
        vector<pi> coords;
        string s;
        while(getline(cin, s) && ln(s))
        {
            stringstream ss(s);
            int x, y;
            ss >> x >> y;
            coords.pb({x, y});
        }
        int ans = 0;
        for(int i = 0; i < sz(coords); i++)
        {
            map<pi, int> cnt;
            for(int j = 0; j < sz(coords); j++)
            {
                if(i == j)
                    continue;
                pi res = combine(coords[i].ff - coords[j].ff, coords[i].ss - coords[j].ss);
                cnt[res]++;
            }
            int mx = 0;
            for(auto x : cnt)
                mx = max(mx, x.ss);
            ans = max(ans, mx + 1);
        }
        cout << ans << endl;
        if(t)
            cout << endl;
    }
    return 0;
}