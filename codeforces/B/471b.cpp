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

int find_freq(map<int, vector<int>> &pos, int f)
{
    int cnt = 0;
    for(auto x : pos)
        if(sz(x.ss) >= f)
            cnt++;
    return cnt;
}

void cp()
{
    int n;
    cin >> n;
    map<int, vector<int>> pos;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pos[x].pb(i);
    }
    bool ok = false;
    vector<int> a, b, c;
    if(find_freq(pos, 3))
    {
        ok = true;
        bool done = false;
        for(auto x : pos)
        {
            if(sz(x.ss) >= 3 && !done)
            {
                a.pb(x.ss[0]), a.pb(x.ss[1]), a.pb(x.ss[2]);
                b.pb(x.ss[0]), b.pb(x.ss[2]), b.pb(x.ss[1]);
                c.pb(x.ss[1]), c.pb(x.ss[0]), c.pb(x.ss[2]);
                for(int i = 3; i < sz(x.ss); i++)
                    a.pb(x.ss[i]), b.pb(x.ss[i]), c.pb(x.ss[i]);
                done = true;
            }
            else
            {
                for(int p : x.ss)
                    a.pb(p), b.pb(p), c.pb(p);
            }
        }
    }
    else if(find_freq(pos, 2) >= 2)
    {
        ok = true;
        int cnt = 0;
        for(auto v : pos)
        {
            if(sz(v.ss) >= 2 && cnt < 2)
            {
                if(cnt == 0)
                {
                    a.pb(v.ss[0]), a.pb(v.ss[1]);
                    b.pb(v.ss[1]), b.pb(v.ss[0]);
                    c.pb(v.ss[1]), c.pb(v.ss[0]);
                }
                else
                {
                    a.pb(v.ss[0]), a.pb(v.ss[1]);
                    b.pb(v.ss[0]), b.pb(v.ss[1]);
                    c.pb(v.ss[1]), c.pb(v.ss[0]);
                }
                cnt++;
                for(int i = 2; i < sz(v.ss); i++)
                    a.pb(v.ss[i]), b.pb(v.ss[i]), c.pb(v.ss[i]);
            }
            else
            {
                for(int p : v.ss)
                    a.pb(p), b.pb(p), c.pb(p);
            }

        }
    }

    if(ok)
    {
        cout << "YES\n";
        for(auto x : a)
            cout << x << " ";
        cout << endl;
        for(auto x : b)
            cout << x << " ";
        cout << endl;
        for(auto x : c)
            cout << x << " ";
        cout << endl;
    }
    else
        cout << "NO\n";
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