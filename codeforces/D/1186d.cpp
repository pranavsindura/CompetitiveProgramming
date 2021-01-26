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
    vector<double> arr(n);
    vector<int> ans(n);
    for(double &x : arr)
        cin >> x;
    ll neg = 0, pos = 0, other = 0;
    for(int i = 0; i < n; i++)
        if(fabs(arr[i] - int(arr[i])) < eps)
            ans[i] = arr[i], other += arr[i];
        else if(arr[i] < 0)
            neg += ceil(arr[i]);
        else
            pos += floor(arr[i]);
    if(other >= 0)
        pos += other;
    else
        neg += other;
    // cout << neg << " " << pos << endl;
    if(abs(neg) > pos)
    {
        ll need = abs(neg) - pos;
        for(int i = 0; i < n; i++)
        {
            if(fabs(arr[i] - int(arr[i])) < eps) continue;
            if(arr[i] > 0 && need > 0)
                ans[i] = ceil(arr[i]), need--;
            else if(arr[i] > 0)
                ans[i] = floor(arr[i]);
            else
                ans[i] = ceil(arr[i]);
        }
    }
    else if(abs(neg) < pos)
    {
        ll need = pos - abs(neg);
        for(int i = 0; i < n; i++)
        {
            if(fabs(arr[i] - int(arr[i])) < eps) continue;
            if(arr[i] < 0 && need > 0)
                ans[i] = floor(arr[i]), need--;
            else if(arr[i] < 0)
                ans[i] = ceil(arr[i]);
            else
                ans[i] = floor(arr[i]);
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(fabs(arr[i] - int(arr[i])) < eps) continue;
            if(arr[i] < 0)
                ans[i] = ceil(arr[i]);
            else if(arr[i] > 0)
                ans[i] = floor(arr[i]);
        }
    }
    for(int x : ans)
        cout << x << endl;
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

