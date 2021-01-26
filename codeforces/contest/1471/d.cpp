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
using pi = pair<ll, ll>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll m1 = 1e9 + 7;
const ll m2 = 1e9 + 9;
const int inf = 1e7;
const int MAXN = 1e6 + 5;

vector<int> prime;
int lp[MAXN];

void init()
{
    lp[0] = lp[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(!lp[i]) lp[i] = i, prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < MAXN; j++)
        {
            lp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;

        }
    }
}

// wtf was i even doing? overcomplicating the heck out of this problem

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    int A = 0, B = 0;

    vector<int> hashA(n);
    map<int, int> freqA, freqB;

    for(int i = 0; i < n; i++)
    {
        ll a = 1;
        map<int, int> exp;
        int temp = arr[i];
        while(temp > 1)
            exp[lp[temp]]++, temp /= lp[temp];
        for(auto x : exp)
            if(x.ss % 2)
                a *= x.ff;
        freqA[a]++;
        hashA[i] = a;
    }

    for(auto x : freqA)
        A = max(A, x.ss);

    for(int i = 0; i < n; i++)
    {
        if(freqA[hashA[i]] % 2 == 0) freqB[1]++;
        else freqB[hashA[i]]++;
    }

    for(auto x : freqB)
        B = max(B, x.ss);

    int q;
    cin >> q;
    while(q--)
    {
        ll k;
        cin >> k;
        if(k == 0) cout << A << endl;
        else cout << B << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

