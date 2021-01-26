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
vector<int> arr[10];
vector<int> pos[10];
void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        arr[i].resize(n);
        pos[i].resize(n + 1);
        for(int j = 0; j < n; j++)
            cin >> arr[i][j], pos[i][arr[i][j]] = j;
    }
    vector<int> pointer(m);
    ll ans = 0;
    int l = 0;

    auto check = [&]()
    {
        // check each pointer if increment is in bounds and
        // new pos has same number
        if(pointer[0] + 1 >= n)
            return false;
        int num = arr[0][pointer[0] + 1];
        for(int i = 1; i < m; i++)
        {
            if(pointer[i] + 1 >= n)
                return false;
            int me = arr[i][pointer[i] + 1];
            if(me != num)
                return false;
        }
        return true;
    };

    auto inc = [&]()
    {
        for(int i = 0; i < m; i++)
            pointer[i]++;
        return true;
    };

    while(l < n)
    {
        pointer[0] = l;
        for(int i = 1; i < m; i++)
            pointer[i] = pos[i][arr[0][l]];

        while(check() && inc());

        int r = pointer[0];
        // add all subarrays of [l, r]
        ll len = r - l + 1;
        ans += len * (len + 1) / 2;
        l = r + 1;
    }
    cout << ans << endl;
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