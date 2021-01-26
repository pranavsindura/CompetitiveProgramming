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

int brute(int i, int arr[], int n, vector<int> ans)
{
    if(i > n)
    {
        int odd = 0, even = 0;
        for(int p = 0; p < sz(ans); p++)
        {
            if(p % 2)
                odd += ans[p];
            else
                even += ans[p];
        }
        // cout<<endl;
        return abs(odd - even);
    }
    else
    {
        int res = brute(i + 1, arr, n, ans);
        ans.pb(arr[i]);
        res = max(res, brute(i + 1, arr, n, ans));
        return res;
    }
}

void cp()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    cout << brute(1, arr, n, vector<int>());
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