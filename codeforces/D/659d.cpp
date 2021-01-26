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
    vector<vector<int>> arr(n + 1, vector<int>(2));
    for(auto &v : arr)
        for(int &x : v)
            cin >> x;

    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        int x = arr[i][0], y = arr[i][1];
        int nx = arr[i + 1][0], ny = arr[i + 1][1];
        int px = arr[i - 1][0], py = arr[i - 1][1];
        
        if(px < x && y == py && nx == x && ny > y) // right, up corner
            ans++;
        else if(x == px && y < py && nx > x && ny == y) // down, right corner
            ans++;
        else if(px > x && py == y && nx == x && ny < y) // left, down corner
            ans++;
        else if(px == x && py < y && nx < x && ny == y) // up, left corner
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