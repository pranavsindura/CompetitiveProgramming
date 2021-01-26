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

int arr[3005];
int pref[3005][3005], suff[3005][3005];

void build(int n)
{
    for(int i = 1; i <= 3000; i++)
        for(int j = 0; j < n; j++)
            pref[i][j] = (j ? pref[i][j - 1] : 0) + (arr[j] == i);
    for(int i = 1; i <= 3000; i++)
        for(int j = n - 1; j >= 0; j--)
            suff[i][j] = (j < n - 1 ? suff[i][j + 1] : 0) + (arr[j] == i);
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build(n);
    ll ans = 0;
    for(int i = 1; i < n; i++)
        for(int j = i + 1; j < n - 1; j++)
            ans += pref[arr[j]][i - 1] * 1LL * suff[arr[i]][j + 1];
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