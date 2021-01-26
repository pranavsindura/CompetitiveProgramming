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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    // Break array into increasing ranges
    vector<pi> inc;
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        if(!st.empty())
        {
            int t = st.top();
            if(arr[t] < arr[i])
            {
                if(sz(st) > 1)
                    st.pop();
            }
            else if(sz(st) == 1)
                st.pop(), inc.pb({t, t});
            else // must be 2
            {
                st.pop();
                int s = st.top();
                st.pop();
                inc.pb({s, t});
            }
        }
        st.push(i);
    }

    if(sz(st) == 1)
    {
        int t = st.top();
        st.pop();
        inc.pb({t, t});
    }
    else if(sz(st) == 2)
    {
        int t = st.top();
        st.pop();
        int s = st.top();
        st.pop();
        inc.pb({s, t});
    }

    int ans = 1;
    for(int i = 0; i < sz(inc); i++)
    {
        ans = max(ans, inc[i].ss - inc[i].ff + 1);
        // We can not bound the ranges and just pick one off the next range or the previous range
        if(sz(inc) > 1)
            ans = max(ans, inc[i].ss - inc[i].ff + 1 + 1);
    }

    for(int i = 0; i < sz(inc) - 1; i++)
    {
        // connect i with i+1
        int l1 = inc[i].ff, r1 = inc[i].ss;
        int l2 = inc[i + 1].ff, r2 = inc[i + 1].ss;
        int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
        int mn = INT_MIN, mx = INT_MAX;
        if(len2 > 1)
            mx = arr[l2 + 1] - 1;
        if(len1 > 1)
            mn = arr[r1 - 1] + 1;
        // increase arr[l2] to mx
        // try to combine arr[l1]->arr[r1] with mx->arr[r2]
        if(mx > arr[r1])
            ans = max(ans, len1 + len2);
        // decrease arr[r1] to mn
        // try to combine arr[l1]->mn with arr[l2]->arr[r2]
        if(mn < arr[l2])
            ans = max(ans, len1 + len2);
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