#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
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
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    int n, k;
    cin >> n >> k;
    if(3 * k > n)
    {
        cout << -1;
        return;
    }
    int ans[n + 1];
    for(int i = 1; i <= n; i++)
    {
        ans[i] = (i % k);
        if(!ans[i])
            ans[i] = k;
    }
    int temp = ans[1];
    for(int i = 1; i < k; i++)
        ans[i] = ans[i + 1];
    ans[k] = temp;
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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