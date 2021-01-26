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

bool is_hill(int a, int b, int c)
{
    return (a < b && c < b);
}

bool is_valley(int a, int b, int c)
{
    return (a > b && c > b);
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    vector<bool> hill(n), valley(n);
    int total = 0;

    for(int i = 1; i < n - 1; i++)
        if(is_hill(arr[i - 1], arr[i], arr[i + 1]))
            total++, hill[i] = 1;
        else if(is_valley(arr[i - 1], arr[i], arr[i + 1]))
            total++, valley[i] = 1;

    int ans = total;

    for(int i = 1; i < n - 1; i++)
    {
        int me = total;
        int was = arr[i];
        // get
        me -= is_hill(arr[i - 1], arr[i], arr[i + 1]);
        me -= is_valley(arr[i - 1], arr[i], arr[i + 1]);
        if(i - 2 >= 0)
        {
            me -= is_hill(arr[i - 2], arr[i - 1], arr[i]);
            me -= is_valley(arr[i - 2], arr[i - 1], arr[i]);
        }
        if(i + 2 < n)
        {
            me -= is_hill(arr[i], arr[i + 1], arr[i + 2]);
            me -= is_valley(arr[i], arr[i + 1], arr[i + 2]);
        }



        // set
        arr[i] = arr[i - 1];
        if(i - 2 >= 0)
        {
            me += is_hill(arr[i - 2], arr[i - 1], arr[i]);
            me += is_valley(arr[i - 2], arr[i - 1], arr[i]);
        }
        if(i + 2 < n)
        {
            me += is_hill(arr[i], arr[i + 1], arr[i + 2]);
            me += is_valley(arr[i], arr[i + 1], arr[i + 2]);
        }
        ans = min(ans, me);
        // undo
        if(i - 2 >= 0)
        {
            me -= is_hill(arr[i - 2], arr[i - 1], arr[i]);
            me -= is_valley(arr[i - 2], arr[i - 1], arr[i]);
        }
        if(i + 2 < n)
        {
            me -= is_hill(arr[i], arr[i + 1], arr[i + 2]);
            me -= is_valley(arr[i], arr[i + 1], arr[i + 2]);
        }


        // set
        arr[i] = arr[i + 1];
        if(i - 2 >= 0)
        {
            me += is_hill(arr[i - 2], arr[i - 1], arr[i]);
            me += is_valley(arr[i - 2], arr[i - 1], arr[i]);
        }
        if(i + 2 < n)
        {
            me += is_hill(arr[i], arr[i + 1], arr[i + 2]);
            me += is_valley(arr[i], arr[i + 1], arr[i + 2]);
        }
        ans = min(ans, me);
        // undo
        if(i - 2 >= 0)
        {
            me -= is_hill(arr[i - 2], arr[i - 1], arr[i]);
            me -= is_valley(arr[i - 2], arr[i - 1], arr[i]);
        }
        if(i + 2 < n)
        {
            me -= is_hill(arr[i], arr[i + 1], arr[i + 2]);
            me -= is_valley(arr[i], arr[i + 1], arr[i + 2]);
        }
        arr[i] = was;
    }

    if(n > 1 && (hill[1] || valley[1]))
        ans = min(ans, total - 1);

    if(n > 1 && (hill[n - 2] || valley[n - 2]))
        ans = min(ans, total - 1);

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

