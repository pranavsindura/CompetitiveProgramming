#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
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
const double PI = acos(-1.0);

struct coord
{
    ll x, y;
    coord(int a, int b)
    {
        x = a, y = b;
    }
};

struct line
{
    ll a, b, c;
    line(int x, int y, int z)
    {
        a = x, b = y, c = z;
    }
};

bool side(coord p, line l)
{
    return (l.a * p.x + l.b * p.y + l.c < 0);
}

void cp()
{
    int x, y;
    cin >> x >> y;
    coord home(x, y);
    cin >> x >> y;
    coord univ(x, y);
    int n;
    cin >> n;
    vector<line> road(n, line(0,0,0));
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        road[i] = line(a, b, c);
    }
    int steps = 0;
    for(int i = 0; i < n; i++)
    {
        if(side(home, road[i]) != side(univ, road[i]))
            steps++;
    }
    cout << steps;
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