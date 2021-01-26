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
    int n, k;
    cin >> n >> k;
    vector<int> books[2][2];
    for(int i = 0; i < n; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;
        books[a][b].pb(t);
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            sort(all(books[i][j]));
            for(int a = 1; a < sz(books[i][j]); a++)
                books[i][j][a] += books[i][j][a - 1];
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < sz(books[1][1]); i++)
    {
        int so_far = i + 1;
        if(so_far >= k)
        {
            ans = min(ans, books[1][1][i]);
            break;
        }
        int left = k - so_far;

        if(sz(books[0][1]) < left)
            continue;
        if(sz(books[1][0]) < left)
            continue;
        int get10 = books[1][0][left - 1];
        int get01 = books[0][1][left - 1];
        int total = books[1][1][i] + get01 + get10;
        ans = min(ans, total);
    }
    if(sz(books[1][0]) >= k && sz(books[0][1]) >= k)
    {
        int total = books[1][0][k - 1] +  books[0][1][k - 1];
        ans = min(ans, total);
    }
    if(ans == INT_MAX)
        ans = -1;
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