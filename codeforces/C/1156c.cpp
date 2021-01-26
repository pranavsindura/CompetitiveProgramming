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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, diff;
    cin >> n >> diff;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    sort(all(arr));
    vector<bool> picked(n);
    int ans = 0;
    int i = 0, j = 1;
    while(i < n && j < n)
    {
        while(i < n && picked[i])
            i++;

        j = max({j, i + 1, n / 2});
        while(j < n && ((arr[j] - arr[i] < diff) || picked[j]))
            j++;

        if(i >= n || j >= n)
            break;
        // Pair (i, j)
        picked[i] = picked[j] = 1;
        ans++;
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