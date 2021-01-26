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

vector<int> prime;
int lp[MAXN];
void init()
{
    lp[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(!lp[i])
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
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int temp = n - i;
        int me = 1;
        map<int, int> freq;
        while(temp > 1)
            freq[lp[temp]]++, temp /= lp[temp];
        for(auto &x : freq)
            me *= (x.ss + 1);
        cnt += me;
    }
    cout << cnt - 1 << endl;
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