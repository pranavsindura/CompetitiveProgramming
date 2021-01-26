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

void cp()
{
    int n;
    cin >> n;
    vector<pair<char, int>> query(2 * n);

    for(int i = 0; i < 2 * n; i++)
    {
        cin >> query[i].ff;
        if(query[i].ff == '-')
            cin >> query[i].ss;
    }

    map<int, int> st;
    vector<int> ans;
    bool ok = true;

    for(int i = 2 * n - 1; i >= 0; i--)
    {
        char t;
        int x;
        t = query[i].ff, x = query[i].ss;
        if(t == '-')
        {
            if(st.empty() || st.begin()->ff > x)
                st.insert({x, 1});
            else
                ok = false;
        }
        else
        {
            if(!st.empty())
                ans.pb(st.begin()->ff), st.erase(st.begin());
            else
                ok = false;
        }
    }

    while(!st.empty())
        ans.pb(st.begin()->ff), st.erase(st.begin());

    cout << (ok ? "YES\n" : "NO\n");
    if(ok)
    {
        while(!ans.empty())
            cout << ans.back() << " ", ans.pop_back();
        cout << endl;
    }
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