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

void cp()
{
    int k, n, m, q;
    cin >> k >> n >> m >> q;
    vector<string> basic(n), comp(m);
    vector<vector<pair<string, int>>> make(m);
    for(auto &x : basic) cin >> x;
    cin.ignore();
    for(int i = 0; i < m; i++)
    {
        string s;
        getline(cin, s);
        for(char &x : s) if(x == ',') x = ' ';
        stringstream ss(s);
        string name;
        ss >> name;
        name.pop_back();
        comp[i] = name;
        int x;
        while(ss >> s >> x)
            make[i].push_back({s, x});
    }
    vector<map<string, int>> hero(k);
    while(q--)
    {
        int h;
        string s;
        cin >> h >> s;
        h--;
        hero[h][s]++;
        for(int i = 0; i < m; i++)
        {
            // try to build ith composite artifact
            bool ok = true;
            for(auto x : make[i])
                if(hero[h][x.ff] < x.ss)
                    ok = false;
            if(ok)
            {
                for(auto x : make[i])
                    hero[h][x.ff] -= x.ss;
                hero[h][comp[i]]++;
            }
        }
    }
    for(int i = 0; i < k; i++)
    {
        int cnt = 0;
        for(auto x : hero[i])
            if(x.ss)
                cnt++;
        cout << cnt << endl;
        for(auto x : hero[i])
            if(x.ss)
                cout << x.ff << " " << x.ss << endl;
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

