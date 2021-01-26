#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;


void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n), freq(100);
    for(int &x : arr)
        cin >> x, x--, freq[x]++;

    int ans = 0;

    int most = 0, mx = 0;
    for(int i = 0; i < 100; i++)
        if(freq[i] > mx)
            mx = freq[i], most = i;

    vector <int> pref(2 * n + 1);
    for(int k = 0; k < 100; k++)
    {
        if(k == most)
            continue;
        fill(all(pref), 2 * n);
        pref[0 + n] = -1;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == most)
                sum++;
            else if(arr[i] == k)
                sum--;
            int p = pref[sum + n];
            ans = max(ans, i - p);
            pref[sum + n] = min(pref[sum + n], i);
        }
    }
    cout << ans << endl;
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