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

string solve(string &a, int &pos)
{
    vector<string> children;
    string me = "0";
    while(pos < ln(a) && a[pos] == '0')
    {
        pos++;
        string s = solve(a, pos);
        children.pb(s);
    }
    sort(all(children));
    for(string &x : children)
        me += x;
    me += "1";
    pos++;
    return me;
}

void cp()
{
    string a, b;
    cin >> a >> b;
    int pos = 0;
    string ans_a = solve(a, pos);
    pos = 0;
    string ans_b = solve(b, pos);
    cout << (ans_a == ans_b ? "same\n" : "different\n");
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