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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for(ll &x : a)
        cin >> x;
    for(ll &x : b)
        cin >> x;

    for(int i = 1; i < n; i++)
        a[i] += a[i - 1];
    for(int i = 1; i < m; i++)
        b[i] += b[i - 1];


    int total = 0;
    for(int i = 0; i < n; i++)
        if(a[i] <= k)
            total = i + 1;
    for(int i = 0; i < n; i++)
    {
        //read [0, i] books from top of A
        int read_a = i + 1;
        ll time_a = a[i];
        if(time_a > k)
            break;

        ll left = k - time_a;

        int lo = 0, hi = m - 1;
        int pos = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(b[mid] <= left)
                pos = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        if(pos == -1)
            continue;

        int read_b = pos + 1;
        // cout << i << ": " << read_a << " " << read_b;
        total = max(total, read_a + read_b);
    }
    for(int i = 0; i < m; i++)
        if(b[i] <= k)
            total = max(total, i + 1);
    for(int i = 0; i < m; i++)
    {
        //read [0, i] books from top of B
        int read_b = i + 1;
        ll time_b = b[i];
        if(time_b > k)
            break;

        ll left = k - time_b;

        int lo = 0, hi = n - 1;
        int pos = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(a[mid] <= left)
                pos = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        if(pos == -1)
            continue;

        int read_a = pos + 1;
        // cout << i << ": " << read_a << " " << read_b;
        total = max(total, read_a + read_b);
    }

    cout << total;
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