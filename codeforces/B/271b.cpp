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
#define clr(x,v) memset(x, v, sizeof(x))
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
const int MAXN = 1000005;
bool is_prime[MAXN];
vector<int> prime;

void init()
{
    clr(is_prime, true);
    for(int i = 2; i < MAXN; i++)
    {
        if(is_prime[i])
            prime.pb(i);
        for(int j = 0; j < sz(prime) && i * prime[j] < MAXN; j++)
        {
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0)
                break;
        }
    }
}

void cp()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    ll cost = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        ll cur = 0;
        for(int j = 0; j < m; j++)
        {
            auto it = lower_bound(all(prime), arr[i][j]);
            cur += *it - arr[i][j];
        }
        cost = min(cost, cur);
    }
    for(int j = 0; j < m; j++)
    {
        ll cur = 0;
        for(int i = 0; i < n; i++)
        {
            auto it = lower_bound(all(prime), arr[i][j]);
            cur += *it - arr[i][j];
        }
        cost = min(cost, cur);
    }
    cout<<cost;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}