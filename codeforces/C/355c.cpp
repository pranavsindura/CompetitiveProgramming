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

void cp()
{
    int n, l, r, q_l, q_r;
    cin >> n >> l >> r >> q_l >> q_r;
    vector<int> arr(n);
    int sum = 0;
    for(int &x : arr)
        cin >> x, sum += x;
    int ans = INT_MAX;
    int sum_left = 0, sum_right = sum;
    for(int i = 0; i <= n; i++)
    {
        int total = sum_left * l + sum_right * r;
        int e_l = i, e_r = n - i;
        int extra = max(0, abs(e_l - e_r) - 1);
        // cout << i << ": " << extra << endl;
        if(e_l > e_r)
            total += q_l * extra;
        else
            total += q_r * extra;
        ans = min(ans, total);
        sum_left += arr[i];
        sum_right -= arr[i];
        // cout<<total<<endl;
    }
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