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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll sum(int l, int r, vector<ll> &pref)
{
    if(l > r)
        return 0;
    return (l ? pref[r] - pref[l - 1] : pref[r]);
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<ll> health(n), arrow(m);
    for(ll &x : health)
        cin >> x;
    for(ll &x : arrow)
        cin >> x;
    for(int i = 1; i < n; i++)
        health[i] += health[i - 1];
    ll excess = 0;
    int pos = 0;
    for(int q = 0; q < m; q++)
    {
        int lo = pos, hi = n - 1;
        int ans = n;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(sum(pos, mid, health) > arrow[q] + excess)
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        if(ans == n)
        {
            // all die
            excess = 0;
            pos = 0;
            cout << n << endl;
        }
        else
        {
            //some remain
            excess = arrow[q] + excess - sum(pos, ans - 1, health);
            pos = ans;
            cout << n - pos << endl;
        }
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