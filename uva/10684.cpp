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
const int MAXN = 1e4 + 5;
int n;
int arr[MAXN];

void cp()
{
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = INT_MIN;
    int sofar = 0;
    for(int i = 0; i < n; i++)
    {
        sofar = max(sofar + arr[i], arr[i]);
        ans = max(ans, sofar);
    }
    if(ans <= 0)
        cout << "Losing streak.\n";
    else
        cout << "The maximum winning streak is " << ans << ".\n";
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(cin >> n && n)
    {
        cp();
    }
    return 0;
}