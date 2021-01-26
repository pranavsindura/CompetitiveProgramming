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
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    if(n == 1)
    {
        cout << "1 1\n";
        cout << -arr[0] << endl;
        cout << "1 1\n0\n1 1\n0\n";
        return;
    }
    cout << 1 << " " << n << endl;
    for(int i = 0; i < n; i++)
    {
        ll add =  - n * 1LL * arr[i];
        arr[i] += add;
        cout << add << " ";
    }
    cout << endl;
    cout << 1 << " " << n - 1 << endl;
    for(int i = 0; i < n - 1; i++)
    {
        cout << -arr[i] << " ";
    }
    cout << endl;
    cout << n << " " << n << endl;
    cout << -arr.back() << endl;
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