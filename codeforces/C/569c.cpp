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
const int MAXN = 2e6 + 5;
vector<int> prime;
bool is_prime[MAXN];
int palin_cnt[MAXN];
int prime_cnt[MAXN];

bool is_palin(string s)
{
    string rev = s;
    reverse(all(rev));
    return rev == s;
}

void init()
{
    clr(is_prime, true);
    is_prime[1] = false;
    for(int i = 2; i < MAXN; i++)
    {
        if(is_prime[i])
            prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < 1LL * MAXN; j++)
        {
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0)
                break;
        }
    }
    for(int i = 1; i < MAXN; i++)
    {
        palin_cnt[i] = palin_cnt[i - 1];
        if(is_palin(to_string(i)))
        {
            palin_cnt[i]++;
        }
    }
    for(int i = 1; i < MAXN; i++)
    {
        prime_cnt[i] = prime_cnt[i - 1];
        if(is_prime[i])
        {
            prime_cnt[i]++;
        }
    }
}
void cp()
{
    int p, q;
    cin >> p >> q;
    int g = __gcd(p, q);
    p /= g, q /= g;
    int ans = -1;
    for(int i = 1; i < MAXN; i++)
    {
        // cnt prime upto i
        if(q * 1LL * prime_cnt[i] <= p * 1LL * palin_cnt[i])
        {
            ans = i;
        }
    }
    if(~ans)
        cout << ans;
    else
        cout << "Palindromic tree is better than splay tree";
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