#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
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
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);
int dp[1005][1005];
bool vis[1005][1005];
int lcs(string &a, int i, string &b, int j)
{
    if(i == sz(a) || j == sz(b))
        return 0;
    if(vis[i][j])
        return dp[i][j];
    vis[i][j] = true;
    if(a[i] == b[j])
        return dp[i][j] = 1 + lcs(a, i + 1, b, j + 1);
    int choice1 = lcs(a, i, b, j + 1);
    int choice2 = lcs(a, i + 1, b, j);
    return dp[i][j] = max(choice1, choice2);
}

int main()
{
    FASTIO;
    string s, t;
    int count = 0;
    getline(cin, s);
    if(s == "#")
        return 0;
    getline(cin, t);
    while(true)
    {
        clr(vis, false);
        cout << "Case #" << ++count << ": you can visit at most " << lcs(s, 0, t, 0) << " cities.\n";
        getline(cin, s);
        if(s == "#")
            return 0;
        getline(cin, t);
    }
    return 0;
}