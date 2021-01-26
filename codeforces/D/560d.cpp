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
const ll mod = 1e9 + 9;
const int MAXN = 1e6 + 5;

string a, b;

// This is similar to tree isomorphism

string canonical_form(string &s)
{
    if(sz(s) & 1)
        return s;
    string l, r;
    for(int i = 0; i < ln(s) / 2; i++)
        l += s[i];
    for(int i = ln(s) / 2; i < ln(s); i++)
        r += s[i];
    l = canonical_form(l);
    r = canonical_form(r);
    if(l < r)
        return l + r;
    else
        return r + l;
}

void cp()
{
    cin >> a >> b;
    a = canonical_form(a);
    b = canonical_form(b);
    cout << (a == b ? "Yes\n" : "No\n");
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