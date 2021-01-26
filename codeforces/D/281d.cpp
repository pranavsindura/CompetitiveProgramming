#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    int ans = 0;
    stack<int> st;
    vector<int> nxt(n, -1), prv(n, -1);
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if(!st.empty()) prv[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if(!st.empty()) nxt[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();

    for(int i = 0; i < n; i++)
    {
        if(~prv[i])
            ans = max(ans, arr[i] ^ arr[prv[i]]);
        if(~nxt[i])
            ans = max(ans, arr[i] ^ arr[nxt[i]]);
    }

    cout << ans << endl;
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

