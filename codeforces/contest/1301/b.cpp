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
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    int mx = 1e9, num = -1;
    int lo = 0, hi = 1e9;
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        int l = 0, r = 1e9;
        bool can = true;
        for(int i = 1; i < n; i++)
        {
            if(arr[i] != -1 && arr[i - 1] != -1)
            {
                int diff = abs(arr[i] - arr[i - 1]);
                if(diff > mid)
                    can = false;
            }
            else if(arr[i] == -1 && arr[i - 1] != -1)
            {
                int ml = arr[i - 1] - mid;
                int mr = arr[i - 1] + mid;
                l = max(ml, l);
                r = min(mr, r);
            }
            else if(arr[i] != -1 && arr[i - 1] == -1)
            {
                int ml = arr[i] - mid;
                int mr = arr[i] + mid;
                l = max(ml, l);
                r = min(mr, r);
            }
        }
        can &= l <= r;
        if(can)
            mx = mid, num = l, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << mx << " " << num << endl;
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

