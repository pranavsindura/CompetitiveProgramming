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
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

struct op
{
    ll l, r, d;
};
#define op struct op

int main()
{
    FASTIO;
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    vector<op> ops(m);
    for(int i = 0; i < m; i++)
    {
        cin >> ops[i].l >> ops[i].r >> ops[i].d;
    }
    vector<ll> freOp(m + 1, 0);
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        freOp[x]++;
        freOp[y + 1]--;
    }
    for(int i = 1; i < m; i++)
    {
        freOp[i] += freOp[i - 1];
    }
    vector<ll> diff(n + 1, 0);
    diff[0] = arr[0];
    for(int i = 1; i < n; i++)
        diff[i] = arr[i] - arr[i - 1];
    for(int i = 0; i < m; i++)
    {
        ll sub = ops[i].d * freOp[i];
        diff[ops[i].l - 1] += sub;
        diff[ops[i].r] -= sub;
    }
    arr[0] = diff[0];
    for(int i = 1; i < n; i++)
        arr[i] = arr[i - 1] + diff[i];
    for(ll x : arr)
        cout << x << " ";
    return 0;
}