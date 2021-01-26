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
const int MAXN = 2e6 + 5;

vector<ll> ans(MAXN, 0);
void init()
{
    // ans[1] = 0
    // ans[2] = 0
    // ans[3] = 4
    ans[3] = 4;

    // Count of Nodes w/ children
    //                0  1     3 for n = 3
    vector<ll> cnt = {3, 1, 0, 1};
    for(int i = 4; i < MAXN; i++)
    {
        // Find new count
        vector<ll> new_cnt = {(cnt[0] % mod + 2 * cnt[1] % mod) % mod, cnt[0] % mod, 0, cnt[1] % mod};

        // Calculate answer
        ans[i] = (new_cnt[3] * 4) % mod + ans[i - 3] % mod;
        ans[i] %= mod;
        cnt = new_cnt;
    }
}

void cp()
{
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

int main()
{
    FASTIO;
    init();
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}