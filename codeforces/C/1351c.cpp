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

void cp(int test)
{
    string s;
    cin >> s;

    int ans = 0;

    map<pair<pi, pi>, bool> vis;

    pi p = {0, 0};
    for(char c : s)
    {
        int nx = p.ff, ny = p.ss;
        if(c == 'N')
            ny--;
        else if(c == 'S')
            ny++;
        else if(c == 'W')
            nx--;
        else
            nx++;
        pi np = {nx, ny};
        if(vis.count(mp(p, np)) || vis.count(mp(np, p)))
            ans++;
        else
            ans += 5;
        vis[mp(p, np)] = 1;
        p = np;
    }
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cp(i);
    }
    return 0;
}