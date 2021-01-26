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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    vector<int> order(n);
    iota(all(order), 0);

    vector<int> ans(n);
    if(a < b)
    {
        sort(all(order), [&](int x, int y)
        {
            if(arr[x] == arr[y])
                return x > y;
            else
                return arr[x] < arr[y];
        });
        while(sz(order) > b)
        {
            int x = order.back();
            order.pop_back();
            ans[x] = 1;
        }
        while(sz(order) > 0)
        {
            int x = order.back();
            order.pop_back();
            ans[x] = 2;
        }
    }
    else if(a > b)
    {
        sort(all(order), [&](int x, int y)
        {
            if(arr[x] == arr[y])
                return x < y;
            else
                return arr[x] < arr[y];
        });
        while(sz(order) > a)
        {
            int x = order.back();
            order.pop_back();
            ans[x] = 2;
        }
        while(sz(order) > 0)
        {
            int x = order.back();
            order.pop_back();
            ans[x] = 1;
        }
    }
    else
    {
        for(int i = 0; i < a; i++) ans[i] = 1;
        for(int i = a; i < n; i++) ans[i] = 2;
    }
    for(int x : ans)
        cout << x << " ";
    cout << endl;
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

