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
    int n;
    string s;
    cin >> n;
    vector<ll> arr(n + 1), pref(n + 1, 0), strpref(n + 1, 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i + 1];
    cin >> s;
    s = " " + s;
    ll total = 0;
    for(int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + arr[i];
        strpref[i] = strpref[i - 1];
        if(s[i] == '1')
        {
            strpref[i] += arr[i], total += arr[i];
        }
    }
    ll ans = total;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '1')
        {
            ans = max(ans, total - strpref[i] + pref[i - 1]);
        }
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