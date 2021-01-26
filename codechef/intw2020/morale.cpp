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

ll sum(int l, int r, std::vector<ll> &v)
{
    return (l ? v[r] - v[l - 1] : v[r]);
}

void cp()
{
    int n, m, k;
    cin >> n >> k >> m;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    vector<ll> pre(n);
    pre[0] = arr[0];
    for(int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + arr[i];
    k = min(n - 1, k);
    int i = 0;
    int ans = 0;
    bool ok = true;
    while(i < n)
    {
        // int j = i + 3 * k - 3;
        int j = i + 2 * k - 1;
        bool ichange = false;
        if(j >= n)
        {
            int diff = j - n - 1;
            j = n - 1;
            i = i - diff;
        }
        // cout << i << " " << j << " "<<sum(i, j, pre) << endl;
        if(sum(i, j, pre) < 1LL * m)
        {
            // arr[i] = INT_MAX;
            if(sum(i, j, pre) == 0)
            {

                ok = false;
            }
            ans++;
        }
        i = j + 1;
    }
    if(ok)
        cout << ans;
    else
        cout << -1;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin>>t;
    while(t--)
    {
        cp();
    }
    return 0;
}