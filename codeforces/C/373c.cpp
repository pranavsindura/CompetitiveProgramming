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

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    sort(all(arr));

    int ans = 0;
    int lo = 0, hi = n / 2 - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        bool ok = true;
        int pos = n - 1;
        for(int i = mid; i >= 0; i--)
        {
            if(arr[i] * 2 <= arr[pos--])
            {
                //ok
            }
            else
                ok = false;
        }
        if(ok)
            ans = mid + 1, lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << n - ans;
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