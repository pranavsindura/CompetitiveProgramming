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

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    arr.pb(0);
    sort(all(arr));
    ll lsum = 0, rsum = 0;
    for(int i = 0; i < sz(arr); i++)
        rsum += arr[i];
    ll total = 0;
    for(int i = 1; i < sz(arr); i++)
    {
        ll d = arr[i] - arr[i - 1];
        ll l = i, r = sz(arr) - i;
        lsum += l * d;
        rsum -= r * d;
        // cout << arr[i] << ": " << lsum + rsum << endl;
        total += lsum + rsum;
    }
    ll den = n;
    ll g = gcd(total, n);
    total /= g;
    den /= g;
    cout << total << " " << den;
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