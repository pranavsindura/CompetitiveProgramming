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
#define dbg(x) cout << #x << ": " << x << endl
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
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> cnt;
    for(int &x : arr)
        cin >> x, cnt[x]++;

    int mx = 0, num = -1;
    for(auto x : cnt)
        if(x.ss > mx)
            mx = x.ss, num = x.ff;
    int idx = -1;
    for(int i = 0; i < n; i++)
        if(arr[i] == num)
            idx = i;
    vector<vector<int>> ans;
    // make everything equal to num

    for(int i = idx + 1; i < n; i++)
        if(arr[i] > num)
            ans.pb({2, i + 1, i});
        else
            ans.pb({1, i + 1, i});

    for(int i = idx - 1; i >= 0; i--)
    {
        int x = arr[i];
        if(x == num) continue;
        if(x < num)
            ans.pb({1, i + 1, i + 2});
        else
            ans.pb({2, i + 1, i + 2});
    }

    cout << sz(ans) << endl;
    for(auto v : ans)
        cout << v[0] << " " << v[1] << " " << v[2] << endl;
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