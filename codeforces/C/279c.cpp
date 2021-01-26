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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    vector<int> up(n), down(n);
    // down[i] is the first position on its right
    // where a[i] > arr[i+1]
    down[n - 1] = INT_MAX;
    for(int i = n - 2; i >= 0 ; i--)
        if(arr[i] > arr[i + 1])
            down[i] = i;
        else
            down[i] = down[i + 1];

    // up[i] is the first position on its left
    // where a[i] < arr[i+1]
    up[n - 1] = INT_MAX;
    for(int i = 0; i < n - 1; i++)
        if(arr[i] < arr[i + 1])
            up[i] = i;
        else
            up[i] = up[i - 1];

    int l, r;
    while(m--)
    {
        cin >> l >> r;
        l--, r--;
        if(r - l + 1 <= 2)
            cout << "Yes\n";
        else
        {
            int u = up[l];
            int d = down[l];

            // Find Last Up and First Down
            // Last Up must come before the First Down
            
            int lo = l, hi = r - 1;
            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if(up[mid] >= l && up[mid] <= r)
                    u = up[mid], lo = mid + 1;
                else if(up[mid] > r)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }

            lo = l, hi = r - 1;
            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if(down[mid] >= l && down[mid] <= r)
                    d = down[mid], hi = mid - 1;
                else if(up[mid] > r)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            cout << (u <= d ? "Yes\n" : "No\n");
        }
    }

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