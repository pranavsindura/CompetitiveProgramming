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
    int x, y;
    point() {}
    point(int x, int y): x(x), y(y) {}
};

ll requirement(point p)
{
    return (p.x + 1) * 1LL * (p.y + 1) - 1;
}

void cp()
{
    int n;
    cin >> n;

    vector<point> coords(n);
    vector<int> arr(n);
    for(point &p : coords)
        cin >> p.x >> p.y;
    for(int &x : arr)
        cin >> x;

    map<int, vector<int>> coords_with_diff;
    for(int i = 0; i < n; i++)
    {
        int diff = coords[i].y - coords[i].x;
        coords_with_diff[diff].pb(i);
    }

    for(auto &p : coords_with_diff)
    {
        sort(all(p.ss), [&](int a, int b)
        {
            //sort on basis of requirement descending
            return requirement(coords[a]) > requirement(coords[b]);
        });
    }

    bool ok = true;
    vector<int> ans;

    for(int i = 0; i < n && ok; i++)
    {
        int diff = arr[i];
        if(coords_with_diff[diff].empty() || requirement(coords[coords_with_diff[diff].back()]) > i)
            ok = false;
        else
            ans.pb(coords_with_diff[diff].back()), coords_with_diff[diff].pop_back();
    }
    if(ok)
    {
        cout << "YES\n";
        for(int x : ans)
            cout << coords[x].x << " " << coords[x].y << endl;
    }
    else
        cout << "NO";
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