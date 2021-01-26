#include<bits/stdc++.h>
#define ll unsigned long long int
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
ll dp[MAXN];
void cp()
{
    unsigned int limit = 10000;
    // cin >> limit;
    ll l, r;
    cin >> l >> r;
    // (10^6)^3 = 10^18
    auto cubicLimit = (ll) limit * limit * limit;

    // index 0 is not used, golomb(1) = 1
    vector<ll> golomb = { 0, 1 };
    // precompute golomb[i] = G(i)
    // and sums[i]     =   G(1) +   G(2) +   G(3) + ... +   G(i)
    // and products[i] = 1*G(1) + 2*G(2) + 3*G(3) + ... + i*G(i)
    vector<ll> sums     = { 0, 1 };
    vector<ll> products = { 0, 1 };
    // stop when products[i] >= 10^18
    for (ll i = 2; products.back() < cubicLimit; i++)
    {
        auto current = 1 + golomb[i - golomb[golomb[i - 1]]];

        golomb  .push_back(current);
        sums    .push_back(current     + sums.back());
        products.push_back(current * i + products.back());
    }

    // will contain the result
    ll sum = 0;
    // find products[index - 1] < i <= products[index]
    auto index = 1;
    for (ll i = 1; i <= r; i++)
    {
        // n = i^3
        auto n = i;

        // find products[index - 1] < i <= products[index]
        while (products[index] < n)
            index++;
        // note: n will be in ascending order, therefore I re-use index from previous iterations
        //       in most cases it will be already the correct value

        // find linear interpolation between products[index - 1] and products[index]

        auto from = products[index - 1];
        auto to   = products[index];
        auto ratio = (n - from) / double(to - from);

        // and apply it to sums[index - 1] and sums[index]
        auto low  = sums[index - 1];
        auto high = sums[index];

        // round up
        auto offset = ceil((high - low) * ratio);
        // note: convert to integer as soon as possible to avoid losing digits due to double's limited precision
        auto result = (ll)offset + low;

        // finished another number ...
        sum += result * result;
    }
    index = 1;
    for (ll i = 1; i <= l - 1 && l - 1 ; i++)
    {
        // n = i^3
        auto n = i;

        // find products[index - 1] < i <= products[index]
        while (products[index] < n)
            index++;
        // note: n will be in ascending order, therefore I re-use index from previous iterations
        //       in most cases it will be already the correct value

        // find linear interpolation between products[index - 1] and products[index]

        auto from = products[index - 1];
        auto to   = products[index];
        auto ratio = (n - from) / double(to - from);

        // and apply it to sums[index - 1] and sums[index]
        auto low  = sums[index - 1];
        auto high = sums[index];

        // round up
        auto offset = ceil((high - low) * ratio);
        // note: convert to integer as soon as possible to avoid losing digits due to double's limited precision
        auto result = (ll)offset + low;

        // finished another number ...
        sum -= result * result;
    }
    // solved another problem !
    cout << sum << endl;
    // dp[1] = 1;
    // int n = 1e4;
    // for(int i = 2; i <= n; i++)
    //     dp[i] = 1 + dp[i - dp[dp[i - 1]]];
    // cout << "x\tG(x)\tx*G(x)\tsum x*G(x)\n";
    // ll sum = 0;
    // for(int i = 1; i <= n; i++)
    //     cout << i << "\t" << dp[i] << "\t\t" << i * dp[i] << "\t\t" << sum + i *dp[i] << endl, sum += i * dp[i];
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