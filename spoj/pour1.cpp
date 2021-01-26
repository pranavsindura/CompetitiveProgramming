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
    int cap_a, cap_b, target;
    cin >> cap_a >> cap_b >> target;
    int g = __gcd(cap_a, cap_b);
    if((target > cap_a && target > cap_b) || target % g != 0)
    {
        cout << -1 << endl;
        return;
    }

    // a,b status and steps
    queue<pair<pi, int>> q;
    q.push({{0, 0}, 0});
    map<pi, bool> vis;
    while(!q.empty())
    {
        pair<pi, int> node = q.front();
        q.pop();
        int a = node.ff.ff;
        int b = node.ff.ss;
        int steps = node.ss;
        vis[mp(a, b)] = true;
        if(a == target || b == target)
        {
            cout << steps << endl;
            return;
        }

        //fill a
        int na = cap_a, nb = b;
        if(!vis.count(mp(na, nb)))
            q.push({{na, nb}, steps + 1}), vis[mp(na, nb)] = true;
        // fill b
        na = a, nb = cap_b;
        if(!vis.count(mp(na, nb)))
            q.push({{na, nb}, steps + 1}), vis[mp(na, nb)] = true;
        //pour a into b
        na = 0, nb = a + b;
        int extra = max(0, nb - cap_b);
        na += extra, nb -= extra;
        if(!vis.count(mp(na, nb)))
            q.push({{na, nb}, steps + 1}), vis[mp(na, nb)] = true;
        // pour b into a
        na = a + b, nb = 0;
        extra = max(0, na - cap_a);
        na -= extra, nb += extra;
        if(!vis.count(mp(na, nb)))
            q.push({{na, nb}, steps + 1}), vis[mp(na, nb)] = true;
        //empty a
        na = 0, nb = b;
        if(!vis.count(mp(na, nb)))
            q.push({{na, nb}, steps + 1}), vis[mp(na, nb)] = true;
        //empty b
        na = a, nb = 0;
        if(!vis.count(mp(na, nb)))
            q.push({{na, nb}, steps + 1}), vis[mp(na, nb)] = true;
    }
    cout << -1 << endl;
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