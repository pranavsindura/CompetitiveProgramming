#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll &x : a)
        cin >> x;
    for(ll &x : b)
        cin >> x;

    vector<int> pos, neg;
    vector<int> indeg(n);
    for(int i = 0; i < n; i++)
        if(b[i] != -1)
            indeg[b[i] - 1]++;
    vector<int> pick;
    for(int i = 0; i < n; i++)
        if(indeg[i] == 0)
            pick.pb(i);
    ll ans = 0;
    while(!pick.empty())
    {
        set<int> st;
        while(!pick.empty())
        {
            int x = pick.back();
            if(a[x] > 0)
            {
                pos.pb(x);
                ans += a[x];
                if(b[x] != -1)
                    a[b[x] - 1] += a[x];
            }
            else
                neg.pb(x);

            if(b[x] != -1)
                indeg[b[x] - 1]--;
            if(b[x] != -1 && indeg[b[x] - 1] == 0)
                st.insert(b[x] - 1);

            pick.pop_back();
        }
        pick = vector<int>(all(st));
    }
    for(int x : neg)
        ans += a[x];
    cout << ans << endl;
    for(int x : pos)
        cout << x + 1 << " ";
    reverse(all(neg));
    for(int x : neg)
        cout << x + 1 << " ";
    cout << endl;
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

