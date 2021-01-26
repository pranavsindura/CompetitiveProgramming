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
const int MAXN = 2e4 + 5;

int arr[MAXN], dp[MAXN], last[MAXN];

void cp(int tc)
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
        cin >> arr[i];
    int best = 0, len = 0, ind = -1;

    for(int i = 0; i < n - 1; i++)
    {
        dp[i] = 0;
        last[i] = MAXN;

        if(i - 1 >= 0 && dp[i - 1] + arr[i] >= dp[i])
            dp[i] = dp[i - 1] + arr[i], last[i] = last[i - 1];

        if((arr[i] > dp[i]) || (arr[i] == dp[i] && last[i] > i))
            dp[i] = arr[i], last[i] = i;

        if((dp[i] > best) || (dp[i] == best && i + 1 - last[i] > len))
            best = dp[i], len = i + 1 - last[i], ind = i;
    }
    if(~ind)
        cout << "The nicest part of route " << tc << " is between stops " << last[ind] + 1 << " and " << ind + 2 << endl;
    else
        cout << "Route " << tc << " has no nice parts" << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cp(i);
    }
    return 0;
}