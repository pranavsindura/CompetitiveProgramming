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
const int MAXN = 1e5 + 5;
int  arr[3][MAXN];
int sz[3];
void cp()
{
    for(int k = 0; k < 3; k++)
        cin >> sz[k];
    for(int k = 0; k < 3; k++)
        for(int i = 0; i < sz[k]; i++)
            cin >> arr[k][i];
    for(int k = 0; k < 3; k++)
        sort(arr[k], arr[k] + sz[k]);

    ll mn = LLONG_MAX;

    vector<int> perm = {0, 1, 2};
    do
    {
        // loop on middle
        // find smaller from left and greater from right
        for(int i = 0; i < sz[perm[1]]; i++)
        {
            int x = arr[perm[1]][i];
            int y_idx = 0;
            int lo = 0, hi = sz[perm[0]] - 1;
            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if(arr[perm[0]][mid] <= x)
                    y_idx = mid, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            int y = arr[perm[0]][y_idx];

            int z_idx = 0;
            lo = 0, hi = sz[perm[2]] - 1;
            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if(arr[perm[2]][mid] >= x)
                    z_idx = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
            int z = arr[perm[2]][z_idx];
            mn = min(mn, (x - y) * 1LL * (x - y) + (y - z) * 1LL * (y - z) + (x - z) * 1LL * (x - z) );

        }
    }
    while(next_permutation(all(perm)));
    cout << mn << endl;
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