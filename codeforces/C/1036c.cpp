#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define eps 0.000000001
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
set<ll> nums;
vector<ll> arr;
void init(int len, int nz, ll num)
{
    nums.insert(num);
    if(len)
    {
        if(nz)
        {
            for(int i = 1; i <= 9; i++)
            {
                init(len - 1, nz - 1, num * 10 + i);
            }
        }
        init(len - 1, nz, num * 10);
    }
}

int bin(ll num)
{
    int ind = 0;
    int lo = 0, hi = sz(arr) - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(arr[mid] <= num)
            ind = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }
    return ind;
}

void cp()
{
    ll l, r;
    cin >> l >> r;
    // cout << arr[bin(r)] << endl;
    cout << bin(r) - bin(l - 1) << endl;
}

int main()
{
    FASTIO;
    int t;
    init(19, 3, 0);
    arr = vector<ll>(all(nums));
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}