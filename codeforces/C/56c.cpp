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

pair<int, map<string, int>> dfs(int &pos, string &s)
{
    pos++;
    
    string my_name;
    while(pos < ln(s) && s[pos] >= 'A' && s[pos] <= 'Z')
        my_name += s[pos], pos++;

    int ans = 0;
    map<string, int> me;

    while(pos < ln(s) && (s[pos] == ':' || s[pos] == ','))
    {
        pair<int, map<string, int>> child = dfs(pos, s);
        ans += child.ff;
        for(auto x : child.ss)
            me[x.ff] += x.ss;
        pos++;
    }

    if(me.count(my_name))
        ans += me[my_name];
    me[my_name]++;

    return {ans, me};
}

void cp()
{
    string s;
    cin >> s;
    s = ":" + s + ".";
    int pos = 0;
    int ans = dfs(pos, s).ff;
    cout << ans;
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