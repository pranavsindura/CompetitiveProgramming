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
const int MAXN = 1e3 + 5;

pair<pi, int> steps[MAXN][MAXN];
bool vis[MAXN][MAXN];
int Ca, Cb, N;

bool valid(int a, int b)
{
    return (a >= 0 && a <= 1000 && b >= 0 && b <= 1000 && !vis[a][b]);
}

void cp()
{
    clr(vis, false);

    queue<pi> q;
    q.push({0, 0});
    int end_a = 0, end_b = 0;
    while(!q.empty())
    {
        pi u = q.front();
        q.pop();
        vis[u.ff][u.ss] = true;
        // cout<<u.ff<<" "<<u.ss<<endl;
        if(u.ss == N)
        {
            end_a = u.ff;
            end_b = u.ss;
            break;
        }
        int na, nb;
        // 0 -> Fill A
        na = Ca, nb = u.ss;
        if(valid(na, nb))
            q.push({na, nb}), vis[na][nb] = true, steps[na][nb] = {u, 0};
        // 1 -> Fill B
        na = u.ff, nb = Cb;
        if(valid(na, nb))
            q.push({na, nb}), vis[na][nb] = true, steps[na][nb] = {u, 1};
        // 2 -> Empty A
        na = 0, nb = u.ss;
        if(valid(na, nb))
            q.push({na, nb}), vis[na][nb] = true, steps[na][nb] = {u, 2};
        // 3 -> Empty B
        na = u.ff, nb = 0;
        if(valid(na, nb))
            q.push({na, nb}), vis[na][nb] = true, steps[na][nb] = {u, 3};
        // 4 -> Pour A B
        na = 0, nb = u.ff + u.ss;
        if(nb > Cb)
            na = nb - Cb, nb = Cb;
        if(valid(na, nb))
            q.push({na, nb}), vis[na][nb] = true, steps[na][nb] = {u, 4};
        // 5 -> Pour B A
        na = u.ff + u.ss, nb = 0;
        if(na > Ca)
            nb = na - Ca, na = Ca;
        if(valid(na, nb))
            q.push({na, nb}), vis[na][nb] = true, steps[na][nb] = {u, 5};
    }
    vector<string> ans;
    while(true)
    {
        if(end_a == 0 && end_b == 0)
            break;
        pair<pi, int> u = steps[end_a][end_b];
        switch(u.ss)
        {
        case 0:
            ans.pb("fill A");
            break;
        case 1:
            ans.pb("fill B");
            break;
        case 2:
            ans.pb("empty A");
            break;
        case 3:
            ans.pb("empty B");
            break;
        case 4:
            ans.pb("pour A B");
            break;
        case 5:
            ans.pb("pour B A");
            break;
        }
        end_a = u.ff.ff, end_b = u.ff.ss;
    }
    for(int i = sz(ans) - 1; i >= 0; i--)
        cout << ans[i] << endl;
    cout << "success\n";
}

int main()
{
    FASTIO;
    while(cin >> Ca >> Cb >> N)
    {
        cp();
    }
    return 0;
}