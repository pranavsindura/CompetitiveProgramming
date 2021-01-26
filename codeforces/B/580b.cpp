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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
int getr(vector<pii> &arr, int x)
{
    int ans = sz(arr) - 1;
    int l = 0, r = sz(arr) - 1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(arr[m].ff <= x)
            ans = m, l = m + 1;
        else
            r = m - 1;
    }
    return ans;
}
ll sum(int i, int j, ll pre[])
{
    ll s = pre[j];
    if(i)
        s -= pre[i - 1];
    return s;

}
int main()
{
    FASTIO;
    int n, d, a, b;
    cin >> n >> d;
    vector<pii> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr[i] = mp(a, b);
    }
    sort(all(arr));
    ll pre[n];
    pre[0] = arr[0].ss;
    for(int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + arr[i].ss;
    }
    ll ans = LLONG_MIN;
    int ind = 0;
    for(pii x : arr)
    {
        a = ind;
        b = getr(arr, x.ff + d - 1);
        ans = max(ans, sum(a, b, pre));
        ind++;
    }
    cout << ans;
    return 0;
}
