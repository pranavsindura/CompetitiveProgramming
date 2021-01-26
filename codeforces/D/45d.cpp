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
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

struct op
{
    int l, r, i;
};

void cp()
{
    int n;
    cin >> n;
    vector<op> arr;
    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        op o;
        o.l = l, o.r = r, o.i = i;
        arr.pb(o);
    }

    sort(all(arr), [&](op a, op b)
    {
        if(a.r == b.r)
            return a.l < b.l;
        return a.r < b.r;
    });

    int cnt = 0;
    vector<int> ans(n);

    for(int i = 1; i <= (int)1e7 && !arr.empty(); i++)
    {
        for(int j = 0; j < sz(arr); j++)
        {
            if(arr[j].l <= i && i <= arr[j].r)
            {
                ans[arr[j].i] = i;
                arr.erase(begin(arr) + j);
                break;
            }
        }
    }
    for(int x : ans)
        cout << x << " ";
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