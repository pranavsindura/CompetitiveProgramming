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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll fpow(ll x, ll y, ll m)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % m * x % m) % m;
        x = (x % m * x % m) % m;
        y = y / 2;
    }
    return res % m;
}
void cp()
{
    // n == 1
    string s;
    cin >> s;
    ll a, b;
    int n = ln(s);
    cin >> a >> b;
    vector<ll> arr;
    for(char x : s)
        arr.pb(x - '0');
    ll left = 0, right = 0;
    ll p = 0, q = 0;
    vector<ll> save_right(n);
    for(int i = n - 1; i >= 0; i--)
    {
        right = (right % b + (arr[i] % b * fpow(10, p, b) % b) % b) % b;
        save_right[i] = right;
        p++;
    }
    int sep = -1;
    for(int i = 1; i < n; i++)
    {
        right = save_right[i];
        left = (left * 10) % a + arr[i - 1];
        left %= a;
        if(arr[i] == 0)
        	continue;
        if(left == 0 && right == 0)
        {
            sep = i;
            break;
        }
    }
    if(sep == -1)
        cout << "NO";
    else
    {
    	cout<<"YES\n";
        for(int i = 0; i < sep; i++)
            cout << arr[i];
        cout << endl;
        for(int i = sep; i < n; i++)
            cout << arr[i];
        cout << endl;
    }
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