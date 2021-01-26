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

int lp[MAXN];
vector<int> prime;
bool present[MAXN];
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
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    int g = arr[0];
    for(int i = 1; i < n; i++)
        g = __gcd(g, arr[i]);
    bool is_pairwise = true;
    for(int i = n - 1; i >= 0 && is_pairwise; i--)
    {
        int temp = arr[i];
        while(temp > 1 && is_pairwise)
        {
            int pf = lp[temp];
            if(present[pf])
                is_pairwise = false;
            while(temp % pf == 0)
                temp /= pf;
            present[pf] = 1;
        }
    }
    if(is_pairwise)
        cout << "pairwise coprime";
    else if(g == 1)
        cout << "setwise coprime";
    else
        cout << "not coprime";
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