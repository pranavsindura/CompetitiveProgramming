#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--)
    {
        vector<int> arr;
        string str;
        while(getline(cin, str) && str != "")
        {
            stringstream ss(str);
            int x;
            ss >> x;
            arr.pb(x);
        }
        int n = sz(arr);
        int dp[n], idx[n];
        dp[0] = 1;
        idx[0] = -1;
        for(int i = 1; i < n; i++)
        {
            int mx_len = 1;
            int ind = -1;
            for(int j = 0; j < i; j++)
            {
                if(arr[j] < arr[i] && dp[j] + 1 > mx_len)
                {
                    mx_len = dp[j] + 1;
                    ind = j;
                }
            }
            dp[i] = mx_len;
            idx[i] = ind;
        }
        int mx_ind = max_element(dp, dp + n) - dp;
        deque<int> ans;
        while(mx_ind != -1)
        {
            ans.push_front(arr[mx_ind]);
            mx_ind = idx[mx_ind];
        }
        cout << "Max hits: " << sz(ans) << endl;
        for(int x : ans)
            cout << x << endl;
        if(t)
            cout << endl;
    }
    return 0;
}