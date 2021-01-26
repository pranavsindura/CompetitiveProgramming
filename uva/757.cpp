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
int n, h;
int dp[30][200][200];
int f[30];
int d[30];
int t[30];

int rec(int pos, int time_left, int mul, int fish_now)
{
    if(pos > n || time_left <= 0)
        return 0;

    int &ret = dp[pos][time_left][mul];

    if(ret != -1)
        return ret;


    fish_now = max(fish_now, 0);
    int same = rec(pos, time_left - 1, mul + 1, fish_now - d[pos]) + fish_now;
    int nxt = rec(pos + 1, time_left - t[pos], 0, f[pos + 1]);

    return ret = max(same, nxt);
}

int arr[30];
void trace(int pos, int time_left, int mul, int fish_now)
{
    if(pos > n || time_left <= 0)
        return;

    fish_now = max(fish_now, 0);
    int same = rec(pos, time_left - 1, mul + 1, fish_now - d[pos]) + fish_now;
    int nxt = rec(pos + 1, time_left - t[pos], 0, f[pos + 1]);

    if(same >= nxt)
    {
        arr[pos]++;
        trace(pos, time_left - 1, mul + 1, fish_now - d[pos]);
    }
    else
    {
        trace(pos + 1, time_left - t[pos], 0, f[pos + 1]);
    }
}

void cp()
{
    int test = 0;
    while(cin >> n && n)
    {
        if(test++)
            cout << endl;
        cin >> h;
        for(int i = 0; i < n; i++)
            cin >> f[i + 1];
        for(int i = 0; i < n; i++)
            cin >> d[i + 1];
        for(int i = 1; i < n; i++)
            cin >> t[i];

        clr(dp, -1);
        clr(arr, 0);
        h = h * 12;
        int ans = rec(1, h, 0, f[1]);
        trace(1, h, 0, f[1]);

        for(int i = 1; i <= n; i++)
        {
            if(i > 1)
                cout << ", ";
            cout << arr[i] * 5;
        }
        cout << endl;
        cout << "Number of fish expected: " << ans << endl;
    }
}

int main()
{
    FASTIO;
    cp();
    return 0;
}