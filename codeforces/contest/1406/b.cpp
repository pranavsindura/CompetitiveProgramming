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
    int n, pos = 0, neg = 0;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
    {
        cin >> x;
        if(x > 0)
            pos++;
        else if(x < 0)
            neg++;
    }
    ll ans = LLONG_MIN;
    sort(all(arr));
    for(int i = 0; i <= 4 && i <= neg; i += 2)
    {
        // take i -ve numbers
        ll me = 1;
        for(int j = 0; j < i; j++)
            me *= arr[j];
        // take 5-i +ve numbers
        for(int j = n - 1; j >= n - (5 - i); j--)
            me *= arr[j];
        ans = max(ans, me);
    }
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