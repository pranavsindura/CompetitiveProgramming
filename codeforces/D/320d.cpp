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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

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
    vector<int> arr(n + 1);
    arr[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<int> eat(n + 1);
    eat[0] = inf;
    stack<int> st;
    st.push(0);

    for(int i = 1; i <= n; i++)
    {
        eat[i] = 1;
        while(!st.empty() && arr[st.top()] < arr[i])
        {
            eat[i] = max(eat[i], eat[st.top()] + 1);
            st.pop();
        }
        st.push(i);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) if(eat[i] < inf) ans = max(ans, eat[i]);
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
