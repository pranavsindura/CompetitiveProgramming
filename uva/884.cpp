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
vector<int> prime;
int lp[MAXN];
int ans[MAXN];
void init()
{
    lp[0] = lp[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(!lp[i])
            lp[i] = i, prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < MAXN; j++)
        {
            lp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0)
                break;
        }
        ans[i] += ans[i - 1];
        int n = i;
        while(n > 1)
        {
            n /= lp[n];
            ans[i]++;
        }
    }
}


int main()
{
    FASTIO;
    int n;
    init();
    while(cin >> n)
    {
        cout << ans[n] << endl;
    }
    return 0;
}