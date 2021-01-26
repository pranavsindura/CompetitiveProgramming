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
int arr[105];
int n;
int dp[101][52][51][2];
int rec(int i, int odd, int even, int last)
{
    if(i == n)
        return 0;

    int &ret = dp[i][odd][even][last];
    if(~ret)
        return ret;

    if(arr[i])
        return ret = ((arr[i] & 1) != last) + rec(i + 1, odd, even, arr[i] & 1);
    else
    {
        int choice1 = 1e7, choice2 = 1e7;
        if(odd)
            choice1 = (last == 0) + rec(i + 1, odd - 1, even, 1);
        if(even)
            choice2 = (last == 1) + rec(i + 1, odd, even - 1, 0);
        return ret = min(choice1, choice2);
    }
}

void cp()
{
    cin >> n;
    int odd = (n + 1) / 2, even = n / 2;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        even -= (arr[i] && arr[i] % 2 == 0 ? 1 : 0);
        odd -= (arr[i] & 1 ? 1 : 0);
    }

    clr(dp, -1);
    int ans = rec(0, odd, even, arr[0] ? arr[0] & 1 : 2);

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