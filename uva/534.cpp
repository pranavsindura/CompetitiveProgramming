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
struct point
{
    double x, y;
    point() {}
    point(double x, double y): x(x), y(y) {}
};
double len(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void cp()
{
    int n;
    int test = 0;
    while(cin >> n && n)
    {

        vector<point> arr;
        for(int i = 0; i < n; i++)
        {
            double x, y;
            cin >> x >> y;
            arr.pb(point(x, y));
        }
        // task: minimax of reaching from 0 to 1
        double adj[n + 1][n + 1];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adj[i][j] = len(arr[i], arr[j]);

        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
                
        cout << "Scenario #" << ++test << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << adj[0][1] + eps << endl;
        cout << endl;
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