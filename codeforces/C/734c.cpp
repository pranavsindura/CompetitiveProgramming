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
const int MAXN = 2e5 + 5;

ll a[MAXN], b[MAXN], c[MAXN], d[MAXN];

void cp()
{
    ll n, x, s;
    int m, k;
    cin >> n >> m >> k >> x >> s;
    for(int i = 0; i < m; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    for(int i = 0; i < k; i++)
        cin >> c[i];
    for(int i = 0; i < k; i++)
        cin >> d[i];

    a[m] = x;
    b[m] = 0;

    ll ans = x * n;
    
    for(int i = 0; i <= m; i++)
    {
        // Use ith potion that decrease time of each
        ll new_time = a[i];
        ll new_budget = s - b[i];
        if(new_budget < 0)
            continue;
        // Buy the maximum potions you can with the budget
        ll max_buy = 0;
        int lo = 0, hi = k - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(d[mid] <= new_budget)
                max_buy = c[mid], lo = mid + 1;
            else
                hi = mid - 1;
        }
        ll rem = n - max_buy;
        ll time_spent = rem * new_time;
        ans = min(ans, time_spent);
    }
    cout << ans;
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