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
const int MAXN = 1e7 + 5;

int lp[MAXN];
ll div_count[MAXN];
vector<int> prime;

void init(int n)
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
    for(int i = 1; i <= n; i++)
    {
        int temp = i;
        map<int, int> freq;
        while(temp > 1)
        {
            freq[lp[temp]]++;
            temp /= lp[temp];
        }
        ll cnt = 1;
        for(auto x : freq)
        {
            cnt *= 1LL * (x.ss + 1);
        }
        div_count[i] = cnt;
    }
}


int main()
{
    FASTIO;
    int n;
    cin >> n;
    init(n);
    ll ans = 0;
    for(int i=1;i<=n;i++)
    	ans += i*1LL*div_count[i];
    cout<<ans;
    return 0;
}