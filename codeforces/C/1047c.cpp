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
const int MAXN = 20000005;
int lp[MAXN];
vector<int> prime;
void init()
{
    lp[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(lp[i] == 0)
            lp[i] = i, prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < 1LL * MAXN; j++)
        {
            lp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0)
                break;
        }
    }
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    int g = arr[0];
    for(int x : arr)
        g = __gcd(g, x);
    for(int &x : arr)
        x = x / g;
    map<int,int> mult;
    for(int i = 0; i < n; i++)
    {
        int temp = arr[i];
        map<int, int> fac;
        while(temp > 1)
        {
            fac[lp[temp]]++, temp = temp / lp[temp];
        }
        for(auto x : fac)
            mult[x.ff]++;
    }
    int mi = INT_MAX;
    for(auto x: mult)
    {
        int del = n - x.ss;
        if(del < mi)
            mi = del;
    }
    if(mi >= n)
        cout << -1;
    else
        cout << mi;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    init();
    while(t--)
    {
        cp();
    }
    return 0;
}