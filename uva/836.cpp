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
int arr[30][30], hist[30][30];
void cp()
{
    string s;
    int n = 0;
    while(getline(cin, s) && !s.empty())
    {
        for(int i = 0; i < ln(s); i++)
            arr[n][i] = s[i] - '0';
        n++;
    }
    for(int j = 0; j < n; j++)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i][j])
                cnt++;
            else
                cnt = 0;
            hist[i][j] = cnt;
        }
    }
    for(int i = 0; i < n; i++)
        hist[i][n] = -1;

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        stack<pi> st;
        int best = 0;
        for(int j = 0; j <= n; j++)
        {
            pi me = {j, hist[i][j]};
            while(!st.empty() && st.top().ss > me.ss)
            {
                int here = (j - st.top().ff) * st.top().ss;
                best = max(best, here);
                me.ff = st.top().ff;
                st.pop();
            }
            st.push(me);
        }
        ans = max(ans, best);
    }
    cout << ans << endl;
}

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
        cp();
        if(t)
            cout << endl;
    }
    return 0;
}