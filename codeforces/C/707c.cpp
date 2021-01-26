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
    ll n;
    cin >> n;
    // n^2 = m^2 - k^2
    // n^2 = (m+k)*(m-k)

    // n is odd
    // m+k = n^2
    // m-k = 1
    // m = (n^2+1)/2
    // k = (n^2-1)/2;

    // n is even
    // m+k = (n^2)/2
    // m-k = 2
    // m = ((n^2)/2+2)/2
    // k = ((n^2)/2-2)/2;

    ll a, b;
    if(n & 1)
    {
        ll n2 = n * n;
        a = (n2 - 1) / 2;
        b = (n2 + 1) / 2;
    }
    else
    {
        ll n2 = n * n;
        a = ((n2 / 2) + 2) / 2;
        b = ((n2 / 2) - 2) / 2;
    }
    if(a && b)
        cout << a << " " << b;
    else
        cout << -1;
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