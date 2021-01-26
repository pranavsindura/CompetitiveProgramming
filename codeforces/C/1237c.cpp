#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

struct point
{
    int x, y, z, id;
    point(int a, int b, int c, int d): x(a), y(b), z(c), id(d) {}
};

auto cmp = [&](const point &a, const point &b)
{
    if(a.z == b.z)
    {
        if(a.y == b.y)
        {
            if(a.x == b.x)
                return a.id < b.id;
            else
                return a.x < b.x;
        }
        else
            return a.y < b.y;
    }
    else
        return a.z < b.z;
};
vector<point> arr;
vector<pi> ans;

point solve_1d(vector<int> &idx)
{
    vector<point> rem;
    for(int i : idx)
        rem.pb(arr[i]);
    sort(all(rem), cmp);
    for(int i = 0; i < sz(rem) - 1; i += 2)
        ans.pb({rem[i].id + 1, rem[i + 1].id + 1});
    if(sz(rem) % 2)
        return rem.back();
    else
        return point(0, 0, 0, -1);
}

point solve_2d(vector<int> &idx)
{
    map<int, vector<int>> my;
    for(int i : idx)
        my[arr[i].y].pb(i);
    vector<point> rem;
    for(auto &v : my)
    {
        point r = solve_1d(v.ss);
        if(r.id != -1)
            rem.pb(r);
    }
    sort(all(rem), cmp);
    for(int i = 0; i < sz(rem) - 1; i += 2)
        ans.pb({rem[i].id + 1, rem[i + 1].id + 1});
    if(sz(rem) % 2)
        return rem.back();
    else
        return point(0, 0, 0, -1);
}

point solve_3d(vector<int> &idx)
{
    map<int, vector<int>> mz;
    for(int i : idx)
        mz[arr[i].z].pb(i);
    vector<point> rem;
    for(auto &v : mz)
    {
        point r = solve_2d(v.ss);
        if(r.id != -1)
            rem.pb(r);
    }
    sort(all(rem), cmp);
    for(int i = 0; i < sz(rem) - 1; i += 2)
        ans.pb({rem[i].id + 1, rem[i + 1].id + 1});
    if(sz(rem) % 2)
        return rem.back();
    else
        return point(0, 0, 0, -1);
}

void cp()
{
    int n;
    cin >> n;
    vector<int> idx;
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr.pb(point(a, b, c, i));
        idx.pb(i);
    }
    solve_3d(idx);
    for(pi x : ans)
        cout << x.ff << " " << x.ss << endl;
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