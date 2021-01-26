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
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    set<int> s;
    for(int &x : arr)
        cin >> x, s.insert(x);
    int ma = *max_element(all(arr));
    int mi = *min_element(all(arr));
    if(sz(s) > k)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    bool ok = true;
    vector<bool> mark(n + 1, false);
    for(int x : s)
        ans.pb(x), mark[x] = true;
    for(int i = 1; i <= n && sz(ans) < k; i++)
    {
        if(!mark[i])
            ans.pb(i), mark[i] = true;
    }
    vector<int> res;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
            res.pb(ans[j]);
    }
    if(ok)
    {
        cout << sz(res) << endl;
        for(int x : res)
            cout << x << " ";
        nl;
    }
    else
    {
        cout << -1 << endl;
    }

}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}