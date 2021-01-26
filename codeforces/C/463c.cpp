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
const int MAXN = 2e3 + 5;

int arr[MAXN][MAXN];
ll d1[2 * MAXN], d2[2 * MAXN];

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d1[i + j] += arr[i][j], d2[i - j + n] += arr[i][j];

    ll odd = 0, even = 0;
    int x1, y1, x2, y2;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((i + j) & 1)
            {
                ll sum = d1[i + j] + d2[i - j + n] - arr[i][j];
                if(sum >= odd) x1 = i, y1 = j, odd = sum;
            }
            else
            {
                ll sum = d1[i + j] + d2[i - j + n] - arr[i][j];
                if(sum >= even) x2 = i, y2 = j, even = sum;
            }
        }
    }
    cout << odd + even << endl;
    cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
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

