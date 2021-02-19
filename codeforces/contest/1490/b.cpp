#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    int need = n / 3;
    vector<int> freq(3);
    for(int x : arr) freq[x % 3]++;

    int ans = 0;
    vector<int> small, big;
    for(int i = 0; i < 3; i++)
        if(freq[i] > need) big.push_back(i);
        else if(freq[i] < need) small.push_back(i);

    if(sz(small) == 1)
    {
        int make = small[0];
        for(int x : big)
        {
            int have = freq[x] - need;
            ans += ((make - x + 3) % 3) * have;
        }
    }
    else if(sz(big) == 1)
    {
        int make = big[0];
        for(int x : small)
        {
            int have = need - freq[x];
            ans += ((x - make + 3) % 3) * have;
        }
    }

    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
