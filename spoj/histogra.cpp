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
const int MAXN = 1e6 + 5;
int n;
ll arr[MAXN];
void cp()
{
    while(true)
    {
        cin >> n;
        if(!n)
            break;

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        stack<pair<int, ll>> st;
        arr[n++] = -1;
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            pair<int, ll> me = {i, arr[i]};
            while(!st.empty() && st.top().ss > me.ss)
            {
                // ll here = (i - st.top().ff) * st.top().ss;
                ans = max(ans, (i - st.top().ff) * st.top().ss);
                me.ff = st.top().ff;
                st.pop();
            }
            st.push(me);
        }
        cout << ans << endl;
    }
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