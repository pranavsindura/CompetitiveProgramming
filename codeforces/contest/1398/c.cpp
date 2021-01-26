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
    string s;
    cin >> n >> s;

    vector<int> arr;
    for(char &x : s)
        arr.pb(x - '0');

    ll ans = 0;
    // pref[r] - pref[l-1] = r - (l-1)
    // r - pref[r] = (l-1) - pref[l-1]
    // r - pref[r] = l - pref[l]

    map<int, int> occ;
    
    vector<int> pref;
    pref.pb(arr.front());
    for(int i = 1; i < n; i++)
        pref.pb(pref.back() + arr[i]);

    occ[0] = 1;
    for(int i = 0; i < n; i++)
        ans += occ[(i + 1) - pref[i]], occ[(i + 1) - pref[i]]++;

    cout << ans << endl;
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