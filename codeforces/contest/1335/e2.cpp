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

int pref[MAXN][201];

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> pos(201);
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i], pos[arr[i]].pb(i);

    for(int i = 0; i < n; i++)
        for(int j = 1; j <= 200; j++)
            pref[i][j] = 0;

    for(int i = 1; i <= 200; i++)
        for(int p : pos[i])
            pref[p][i] = 1;

    for(int i = 1; i <= 200; i++)
        for(int j = 1; j < n; j++)
            pref[j][i] += pref[j - 1][i];

    int ans = INT_MIN;
    for(auto &v : pos)
        ans = max(ans, sz(v));

    for(int d = 1; d <= 200; d++)
    {
        for(int i = 0; i < sz(pos[d]) / 2; i++)
        {
            int l = pos[d][i], r = pos[d][sz(pos[d]) - i - 1];
            for(int j = 1; j <= 200; j++)
            {
                if(j == d)
                    continue;
                int cnt = pref[r][j] - (l ? pref[l - 1][j] : 0);
                ans = max(ans, cnt + 2 * (i + 1));
            }
        }
    }
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