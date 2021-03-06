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

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int pos = 0;
    ll total = 0;

    for(int &x : arr)
        cin >> x, pos += (x > 0), total += (x > 0 ? x : 0);

    vector<int> ans;
    for(int i = 0; i < pos; i++)
        if(arr[i] < 0)
            ans.pb(i);
    for(int i = pos; i < n; i++)
        if(arr[i] > 0)
            ans.pb(i);

    cout << total << endl;
    cout << sz(ans) << " ";
    for(int x : ans)
        cout << x + 1 << " ";
    cout << endl;
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