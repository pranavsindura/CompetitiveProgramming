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
    int n, p;
    cin >> n >> p;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    vector<int> ans;
    sort(all(arr));

    for(int x = 1; x <= 2000; x++)
    {
        //check validity
        bool ok = true;
        int num = x;
        for(int i = 0; i < n; i++)
        {
            int lo = i, hi = n - 1;
            ll here = 0;
            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if(num >= arr[mid])
                    here = mid - i + 1, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            if(here % p == 0)
                ok = false;
            if(arr[i] <= num)
                num++;
            else
                ok = false;
        }
        if(ok)
            ans.pb(x);
    }
    cout << sz(ans) << endl;
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