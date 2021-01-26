#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    ll n, m, v;
    cin >> n >> m >> v;
    if(m > n * (n - 1) / 2 || m < n - 1)
    {
        cout << -1;
        return;
    }
    int a, b;
    vector<pi> edge;
    for(int i = 1; i <= n; i++)
    {
        if(i != v)
        {
            a = i;
            edge.pb({v, a});
            break;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(i != v && i != a)
        {
            b = i;
            edge.pb({v, b});
            break;
        }
    }
    m -= 2;
    for(int i = 1; i <= n && m; i++)
    {
        if(i == a)
            continue;
        for(int j = i + 1; j <= n && m; j++)
        {
            if(j == a)
                continue;
            pi e = {i, j};
            if(e != pi{b, v} && e != pi{v, b})
            {
                edge.pb({i, j});
                m--;
            }
        }
    }
    if(m)
        cout << -1;
    else
        for(pi x : edge)
            cout << x.ff << " " << x.ss << endl;
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