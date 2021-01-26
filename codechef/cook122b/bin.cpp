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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0;
    vector<pi> range;
    for(char x : s)
    {
        if(x == '0')
            cnt++;
        else
        {
            if(cnt)
                range.pb({-cnt, 2});
            cnt = 0;
        }
    }
    if(cnt)
        range.pb({-cnt, 2});
    if(ln(s) == 1)
    {
        if(s.front() == '0')
            range[0].ss = 1;
    }
    else
    {
        if(s.front() == '0')
            range[0].ss = 1;
        if(s.back() == '0')
            range.back().ss = 1;
    }
    sort(all(range));

    vector<bool> checked(sz(range), false);

    for(int i = 0; i < sz(range); i++)
    {
        if(k >= range[i].ss)
            k -= range[i].ss, checked[i] = true;
    }

    int ans = 0;
    for(int i = 0; i < sz(range); i++)
        if(!checked[i])
            ans -= range[i].ff;

    cout << ans << endl;
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