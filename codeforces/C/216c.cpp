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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pi> emp;
    vector<int> ans;
    for(int d = 0; d < n + m + 2; d++)
    {
        int cnt = 0;
        for(pi x : emp)
            cnt += x.ff;
        for(int i = cnt; i < k; i++)
            emp.pb({1, n}), ans.pb(d + 1);
        int lastday = 0, work = 0;
        for(pi x : emp)
            if(x.ff)
                work++, lastday += x.ss == 1;
        if(work == lastday)
            emp.pb({1, n}), ans.pb(d + 1);
        for(pi &x : emp)
        {
            x.ss--;
            if(x.ss == 0)
            {
                if(x.ff == 1)
                    x = {0, m};
                else
                    x = {1, n};
            }
        }
    }
    cout << sz(ans) << endl;
    for(int x : ans)
        cout << x << " ";
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