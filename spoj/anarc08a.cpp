#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void bfs(string &S, map<string, int> &m, int MX)
{
    set<string> vis;
    queue<pair<string, int>> q;
    q.push({S, 0});
    while(!q.empty())
    {
        pair<string, int> u = q.front();
        q.pop();
        string S = u.ff;
        int depth = u.ss;

        if(depth > MX) continue;
        m[S] = depth;
        vis.insert(S);

        // A CW
        string T = S;
        char a = T[0];
        T[0] = T[3], T[3] = T[4], T[4] = T[1], T[1] = a;
        if(!vis.count(T)) q.push({T, depth + 1}), vis.insert(T);
        // A CCW
        T = S;
        a = T[0];
        T[0] = T[1], T[1] = T[4], T[4] = T[3], T[3] = a;
        if(!vis.count(T)) q.push({T, depth + 1}), vis.insert(T);

        // B CW
        T = S;
        a = T[1];
        T[1] = T[4], T[4] = T[5], T[5] = T[2], T[2] = a;
        if(!vis.count(T)) q.push({T, depth + 1}), vis.insert(T);
        // B CCW
        T = S;
        a = T[1];
        T[1] = T[2], T[2] = T[5], T[5] = T[4], T[4] = a;
        if(!vis.count(T)) q.push({T, depth + 1}), vis.insert(T);

        // C CW
        T = S;
        a = T[3];
        T[3] = T[6], T[6] = T[7], T[7] = T[4], T[4] = a;
        if(!vis.count(T)) q.push({T, depth + 1}), vis.insert(T);
        // C CCW
        T = S;
        a = T[3];
        T[3] = T[4], T[4] = T[7], T[7] = T[6], T[6] = a;
        if(!vis.count(T)) q.push({T, depth + 1}), vis.insert(T);

        // D CW
        T = S;
        a = T[4];
        T[4] = T[7], T[7] = T[8], T[8] = T[5], T[5] = a;
        if(!vis.count(T)) q.push({T, depth + 1}), vis.insert(T);
        // D CCW
        T = S;
        a = T[4];
        T[4] = T[5], T[5] = T[8], T[8] = T[7], T[7] = a;
        if(!vis.count(T)) q.push({T, depth + 1}), vis.insert(T);
    }
}

void cp()
{
    string target;
    map<string, int> R;
    for(char a = '1'; a <= '9'; a++) target += a;
    bfs(target, R, 5);
    string s;
    int test = 0;
    while(cin >> s && s != string(10, '0'))
    {
        int Y = s[0] - '0';
        reverse(all(s));
        s.pop_back();
        reverse(all(s));

        map<string, int> L;

        bfs(s, L, 4);

        int ans = inf;
        for(auto x : L)
            if(R.count(x.first))
                ans = min(ans, x.second + R[x.first]);
        if(ans > Y) ans = -1;
        cout << ++test << ". " << ans << endl;
    }
}

int main()
{
    FASTIO;
    int T;
    T = 1;
    // cin >> T;
    while(T--)
    {
        cp();
    }
    return 0;
}

