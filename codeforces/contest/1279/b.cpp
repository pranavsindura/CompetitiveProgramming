#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vpii vector<pii>
#define vll vector<ll>
const double PI = acos(-1.0);
using namespace std;


int f(vector<int> pre, int l, int r)
{
    int sum = pre[r];
    if(l)
        sum -= pre[l];
    return sum;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> arr(n), pre(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        pre[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + arr[i];
        }
        int ans;
        if(pre[n - 1] <= s)
        {
            cout << 0 << endl;
            continue;
        }
        int maxverse = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            int shift = s + arr[i];
            auto it = upper_bound(all(pre), shift);
            int curr;
            if(it == pre.end())
            {
                curr = n - 1;
            }
            else
            {
                int ind = it - pre.begin() - 1;
                if(ind < i)
                {
                	break;
                }
                else
                {
                	curr=ind;
                }
            }
            if(curr > maxverse)
            {
                maxverse = curr;
                ans = i + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}