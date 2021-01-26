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
const ll inf = 1e16;

ll dp[MAXN][3];

vector<int> arr;

void factorize(ll n, vector<int> &pf)
{
    if(n % 2 == 0)
    {
        pf.pb(2);
        while(n % 2 == 0)
            n /= 2;
    }

    for(ll i = 3; i <= sqrt(n); i += 2)
    {
        if(n % i == 0)
        {
            pf.pb(i);
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1)
        pf.pb(n);
}

void cp()
{
    int n;
    ll a, b;
    cin >> n >> a >> b;
    arr.resize(n);
    for(int &x : arr)
        cin >> x;

    auto ok = [&](int a, int b)
    {
        return a % b == 0;
    };

    ll ans = inf;
    vector<int> first[3], last[3];
    for(int i = -1; i <= 1; i++)
        factorize(arr[0] + i, first[i + 1]);
    for(int i = -1; i <= 1; i++)
        factorize(arr[n - 1] + i, last[i + 1]);

    for(int k = 0; k < 3; k++)
    {
        for(int x : first[k])
        {
            for(int i = 0; i < n; i++)
                dp[i][0] = dp[i][1] = dp[i][2] = inf;
            dp[n][0] = dp[n][1] = dp[n][2] = 0;
            for(int i = n - 1; i > 0; i--)
            {
                // solve dp[i][0]
                if(ok(arr[i], x))
                    dp[i][0] = min(dp[i][0], dp[i + 1][0]);
                if(ok(arr[i] + 1, x) || ok(arr[i] - 1, x))
                    dp[i][0] = min(dp[i][0], b + dp[i + 1][0]);
                dp[i][0] = min(dp[i][0], a + dp[i + 1][1]);

                // solve dp[i][1]
                dp[i][1] = min(dp[i][1], a + dp[i + 1][1]);
                if(ok(arr[i], x))
                    dp[i][1] = min(dp[i][1], dp[i + 1][2]);
                if(ok(arr[i] + 1, x) || ok(arr[i] - 1, x))
                    dp[i][1] = min(dp[i][1], b + dp[i + 1][2]);

                // solve dp[i][2]
                if(ok(arr[i], x))
                    dp[i][2] = min(dp[i][2], dp[i + 1][2]);

                if(ok(arr[i] + 1, x) || ok(arr[i] - 1, x))
                    dp[i][2] = min(dp[i][2], b + dp[i + 1][2]);
            }
            ans = min(ans, dp[1][0] + (k % 3 == 1 ? 0 : b));
        }
    }

    for(int k = 0; k < 3; k++)
    {
        for(int x : last[k])
        {
            for(int i = 0; i < n; i++)
                dp[i][0] = dp[i][1] = dp[i][2] = inf;
            dp[n - 1][0] = dp[n - 1][1] = dp[n - 1][2] = 0;
            for(int i = n - 2; i >= 0; i--)
            {
                // solve dp[i][0]
                if(ok(arr[i], x))
                    dp[i][0] = min(dp[i][0], dp[i + 1][0]);
                if(ok(arr[i] + 1, x) || ok(arr[i] - 1, x))
                    dp[i][0] = min(dp[i][0], b + dp[i + 1][0]);
                dp[i][0] = min(dp[i][0], a + dp[i + 1][1]);

                // solve dp[i][1]
                dp[i][1] = min(dp[i][1], a + dp[i + 1][1]);
                if(ok(arr[i], x))
                    dp[i][1] = min(dp[i][1], dp[i + 1][2]);
                if(ok(arr[i] + 1, x) || ok(arr[i] - 1, x))
                    dp[i][1] = min(dp[i][1], b + dp[i + 1][2]);

                // solve dp[i][2]
                if(ok(arr[i], x))
                    dp[i][2] = min(dp[i][2], dp[i + 1][2]);

                if(ok(arr[i] + 1, x) || ok(arr[i] - 1, x))
                    dp[i][2] = min(dp[i][2], b + dp[i + 1][2]);
            }
            ans = min(ans, dp[0][0] + (k % 3 == 1 ? 0 : b));
        }
    }

    cout << ans << endl;
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