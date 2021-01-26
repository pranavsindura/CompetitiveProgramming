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

void cp()
{
    int n, m;
    cin >> n;
    map<int, bool> exist;
    exist[0] = 1, exist[INT_MAX] = 1;

    vector<int> a(n);
    for(int &x : a)
        cin >> x, exist[x] = 1;

    cin >> m;
    vector<int> b(m);
    for(int &x : b)
        cin >> x, exist[x] = 1;

    sort(all(a)), sort(all(b));

    ll mxa = 0, mxb = INT_MAX;
    for(auto p : exist)
    {
        int d = p.ff;
        // first a_pos numbers are worth 2 points, remaining n-a_pos are are 3 points
        auto a_pos = upper_bound(all(a), d) - begin(a);
        auto b_pos = upper_bound(all(b), d) - begin(b);
        ll aval = a_pos * 2 + (n - a_pos) * 3;
        ll bval = b_pos * 2 + (m - b_pos) * 3;
        if(aval - bval > mxa - mxb || (aval - bval == mxa - mxb && aval > mxa))
            mxa = aval, mxb = bval;
    }
    
    cout << mxa << ":" << mxb;
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