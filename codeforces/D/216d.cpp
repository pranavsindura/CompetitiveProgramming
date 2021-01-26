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
    vector<vector<int>> arr(n), left(n), right(n);
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr[i] = left[i] = right[i] = vector<int>(k);
        for(int &x : arr[i])
            cin >> x;
        sort(all(arr[i]));
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < sz(arr[i]); j++)
        {
            int nx = (i - 1 + n) % n;
            int lo = 0, hi = sz(arr[nx]) - 1;
            int me = 0;
            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if(arr[nx][mid] < arr[i][j])
                    me = mid + 1, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            left[i][j] =  me;

            nx = (i + 1) % n;
            lo = 0, hi = sz(arr[nx]) - 1;
            me = 0;
            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if(arr[nx][mid] < arr[i][j])
                    me = mid + 1, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            right[i][j] = me;
        }

        for(int j = 1; j < sz(arr[i]); j++)
        {
            int l = left[i][j] - (j ? left[i][j - 1] : 0);
            int r = right[i][j] - (j ? right[i][j - 1] : 0);
            if(l != r)
                ans++;
        }
    }
    cout << ans;
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