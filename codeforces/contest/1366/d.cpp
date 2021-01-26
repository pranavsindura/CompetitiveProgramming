#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e7 + 5;

// Linear Sieve
int lp[MAXN];
vector<int> prime;
void init()
{
    lp[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            prime.pb(i);
        }
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < 1LL * MAXN; j++)
        {
            lp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0)
                break;
        }
    }
}

void factorise(int n, map<int, int> &m)
{
    while(n > 1)
    {
        m[lp[n]]++;
        n = n / lp[n];
    }
}

int fpow(int x, int y)
{
    int res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x;
        x = x * x;
        y = y / 2;
    }
    return res;
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    vector<int> d1, d2;
    for(int i = 0; i < n; i++)
    {
        map<int, int> freq;
        factorise(arr[i], freq);
        bool found = false;
        for(auto x : freq)
        {
        	// a = p1^e1
        	// b = n/a
            int a = fpow(x.ff, x.ss);
            int b = arr[i] / a;
            if(a > 1 && b > 1 && __gcd(a + b, arr[i]) == 1)
            {
                d1.pb(a), d2.pb(b);
                found = true;
                break;
            }
        }
        if(!found)
            d1.pb(-1), d2.pb(-1);
    }
    for(int x : d1)
        cout << x << " ";
    cout << endl;
    for(int x : d2)
        cout << x << " ";
    cout << endl;
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