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

const int M = 1e4 + 5;

map<string, int> comp;
int get_idx(string &s)
{
    if(comp.count(s)) return comp[s];
    else return comp[s] = sz(comp) - 1;
}

void shuffle()
{
    int n = sz(comp);
    vector<int> idx(n);
    iota(all(idx), 0);
    random_shuffle(all(idx));

    for(auto &ingredient : comp)
        ingredient.ss = idx.back(), idx.pop_back();
}

ll score(vector<vector<int>> &ans, vector<vector<int>> &pizza)
{
    ll _score = 0;
    for(auto &P : ans)
    {
        set<int> distinct;
        for(int i : P)
            for(int ingredient : pizza[i])
                distinct.insert(ingredient);
        _score += sz(distinct) * sz(distinct);
    }
    return _score;
}

void cp()
{
    int n;
    vector<int> teams(5);
    cin >> n >> teams[2] >> teams[3] >> teams[4];

    vector<vector<string>> input;
    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<string> B;
        for(int j = 0; j < m; j++)
        {
            string x;
            cin >> x;
            B.push_back(x);
            get_idx(x);
        }
        sort(all(B));
        reverse(all(B));
        input.push_back(B);
    }

    ll best = 0;
    vector<vector<int>> _ans;

    int ITR = 100;
    while(ITR--)
    {
        shuffle();

        vector<vector<int>> pizza;
        for(int i = 0; i < n; i++)
        {
            vector<int> B;
            for(string &x : input[i])
                B.push_back(get_idx(x));
            sort(all(B));
            reverse(all(B));
            pizza.push_back(B);
        }

        // group by the smallest ingredient present
        vector<vector<int>> adj(M);
        for(int i = 0; i < n; i++)
            adj[pizza[i].back()].push_back(i);

        vector<vector<int>> ans, to_calc;
        // {p0, p2, p3}
        // {p1, p4}
        for(int k = 4; k >= 2; k--)
        {
            for(int t = 0; t < teams[k]; t++)
            {
                vector<int> take;
                // Check if there are 4 pizzas
                int cnt = 0;
                for(int i = 0; i < M && cnt < k; i++)
                    if(sz(adj[i]) > 0)
                        cnt++;

                // No have
                if(cnt != k) break;

                // Have and assign
                for(int i = 0; i < M && cnt; i++)
                    if(sz(adj[i]) > 0)
                    {
                        take.push_back(adj[i].back());
                        adj[i].pop_back();
                        cnt--;
                    }
                ans.push_back(take);
            }
        }

        ll s = score(ans, pizza);
        if(s > best)
            best = s, _ans = ans;
    }

    // dbg(best);

    // Print
    cout << sz(_ans) << endl;
    for(auto &P : _ans)
    {
        cout << sz(P) << " ";
        for(int x : P)
            cout << x << " ";
        cout << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    srand(time(NULL));
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

