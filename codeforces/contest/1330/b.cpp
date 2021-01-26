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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
    {
        cin >> x;
    }
    int mx = *max_element(all(arr));
    bool left = false, right = false;
    set<int> l, r;
    for(int i = 0; i < mx; i++)
    {
        l.insert(arr[i]);
    }
    for(int i = mx; i < n; i++)
    {
        r.insert(arr[i]);
    }
    set<pii> res;
    if(*l.begin() == 1 && *l.rbegin() == mx && sz(l) == mx && *r.begin() == 1 && *r.rbegin() == sz(r) && sz(r) == n - mx)
        res.insert(mp(mx, n - mx));
    l.clear(), r.clear();
    for(int i = 0; i < n - mx; i++)
    {
        l.insert(arr[i]);
    }
    for(int i = n - mx; i < n; i++)
    {
        r.insert(arr[i]);
    }
    if(*l.begin() == 1 && *l.rbegin() == n - mx && sz(l) == n - mx && *r.begin() == 1 && *r.rbegin() == sz(r) && sz(r) == mx)
        res.insert(mp(n - mx, mx));

    cout << sz(res) << endl;
    for(pii x : res)
        cout << x.ff << " " << x.ss << endl;
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