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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

map<string, int> comp;
vector<vector<string>> relation(1, vector<string>());

int get_idx(string &s)
{
    if(!comp.count(s))
    {
        comp[s] = sz(comp) - 1;
        relation.push_back(vector<string>());
    }
    return comp[s];
}

void cp()
{
    int n, m;
    cin >> n >> m;
    comp["?"] = 0; // Peter's number
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string> split;
        while(ss >> s)
            split.push_back(s);
        int id = get_idx(split[0]);
        if(sz(split) > 3)
        {
            relation[id].push_back(to_string(get_idx(split[2])));
            relation[id].push_back(split[3]);
            relation[id].push_back(to_string(get_idx(split[4])));

        }
        else
        {
            relation[id].push_back(split[2]);
        }
    }

    string mn(m, '1'), mx(m, '0');
    vector<int> val(sz(comp));
    for(int i = 0; i < m; i++)
    {
        vector<int> ones(2);
        for(int j = 0; j < 2; j++)
        {
            fill(all(val), 0);
            val[0] = j;
            for(int k = 1; k <= n; k++)
            {
                if(sz(relation[k]) == 1) val[k] = relation[k][0][i] - '0';
                else if(relation[k][1] == "XOR") val[k] = val[stoi(relation[k][0])] ^ val[stoi(relation[k][2])];
                else if(relation[k][1] == "AND") val[k] = val[stoi(relation[k][0])] & val[stoi(relation[k][2])];
                else if(relation[k][1] == "OR") val[k] = val[stoi(relation[k][0])] | val[stoi(relation[k][2])];
            }
            ones[j] = count(1 + all(val), 1);
        }
        if(ones[0] <= ones[1]) mn[i] = '0';
        else mn[i] = '1';
        if(ones[0] >= ones[1]) mx[i] = '0';
        else mx[i] = '1';
    }

    cout << mn << endl;
    cout << mx << endl;
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
