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
    int a;
    string s;
    cin >> a >> s;
    map<int, int> cnt;
    int n = ln(s);

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += s[j] - '0';
            cnt[sum]++;
        }
    }

    ll ans = 0;
    for(int i = 1; i <= sqrt(a); i++)
    {
        if(a % i == 0)
        {
            int x = i, y = a / i;
            if(x == y)
                ans += cnt[x] * 1LL * cnt[x];
            else
                ans += cnt[x] * 2LL * cnt[y];
            // cout << "(" << x << "," << y << "): (" << cnt[x] << "," << cnt[y] << ")\n";
        }
    }

    if(a == 0)
    {
        ll total = n * 1LL * (n + 1) / 2;
        ll zero = cnt[0];
        ll non_zero = total - zero;
        ans += zero * non_zero * 2 + zero * zero;
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