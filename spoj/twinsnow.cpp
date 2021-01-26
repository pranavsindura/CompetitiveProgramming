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
typedef tuple<int, int, int, int, int, int> snow;
void cp()
{
    int n;
    cin >> n;
    map<snow, int> freq;
    for(int i = 0; i < n; i++)
    {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        freq[ make_tuple(a, b, c, d, e, f) ]++;
        freq[ make_tuple(b, c, d, e, f, a) ]++;
        freq[ make_tuple(c, d, e, f, a, b) ]++;
        freq[ make_tuple(d, e, f, a, b, c) ]++;
        freq[ make_tuple(e, f, a, b, c, d) ]++;
        freq[ make_tuple(f, a, b, c, d, e) ]++;

        swap(a, f);
        swap(b, e);
        swap(c, d);

        freq[ make_tuple(a, b, c, d, e, f) ]++;
        freq[ make_tuple(b, c, d, e, f, a) ]++;
        freq[ make_tuple(c, d, e, f, a, b) ]++;
        freq[ make_tuple(d, e, f, a, b, c) ]++;
        freq[ make_tuple(e, f, a, b, c, d) ]++;
        freq[ make_tuple(f, a, b, c, d, e) ]++;
    }
    bool ok = true;
    for(auto x : freq)
    {
        if(x.ss > 1)
            ok = false;
    }
    if(ok)
        cout << "No two snowflakes are alike.";
    else
        cout << "Twin snowflakes found.";
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