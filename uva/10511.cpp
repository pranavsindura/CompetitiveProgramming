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
const int MAXN = 3e3 + 5;

// Ford-Fulkerson Algorithm
// Edmonds-Karp variant
// flow can be map<int, int>[]
int N; // Total number of nodes, < MAXN
map<int, int> flow[MAXN]; // Dont forget to clear the flow in case of multiple TC
int vis[MAXN], path[MAXN];

int find_path(int S, int T)
{
    fill(vis, vis + N, 0);
    queue<pi> q;
    q.push({S, inf});
    path[S] = -1;
    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int u = node.ff, mx = node.ss;
        vis[u] = 1;
        if(u == T) return mx;
        // for(int v = 0; v < N; v++)
        //     if(!vis[v] && flow[u][v] > 0)
        //         vis[v] = 1, path[v] = u, q.push({v, min(mx, flow[u][v])});
        for(auto v : flow[u])
        if(!vis[v.ff] && v.ss > 0)
            vis[v.ff] = 1, path[v.ff] = u, q.push({v.ff, min(mx, v.ss)});
    }
    return 0;
}

int max_flow(int S, int T)
{
    int ans = 0, d, u;
    while(true)
    {
        d = find_path(S, T);
        if(d == 0) break;
        ans += d;
        u = T;
        while(~path[u])
            flow[path[u]][u] -= d, flow[u][path[u]] += d, u = path[u];
    }
    return ans;
}

map<string, int> comp;
map<int, string> revcomp;
int get_idx(string s)
{
    if(comp.count(s))
        return comp[s];
    else
    {
        comp[s] = sz(comp) - 1;
        revcomp[comp[s]] = s;
        return comp[s];
    }
}

void cp()
{
    comp.clear(), revcomp.clear();
    string input;

    vector<int> persons;
    set<int> parties, clubs;
    vector<array<int, 2>> person_club, person_party;

    while(getline(cin, input) && ln(input) > 0)
    {
        stringstream ss(input);
        vector<string> input_split;
        string input_split_part;
        while(ss >> input_split_part)
            input_split.push_back(input_split_part);

        int person = get_idx(input_split[0] + "!");
        int party = get_idx(input_split[1] + "@");
        vector<int> club_list;
        for(int i = 2; i < sz(input_split); i++)
            club_list.push_back(get_idx(input_split[i] + "#"));

        persons.push_back(person);
        parties.insert(party);
        person_party.push_back({ person, party });
        for(int club : club_list)
        {
            person_club.push_back({ person, club }), clubs.insert(club);
        }
    }

    N = sz(comp) + 2;

    for(int i = 0; i < N; i++) flow[i].clear();
    int S = sz(comp), T = sz(comp) + 1;

    for(int party : parties)
        flow[S][party] = sz(clubs) / 2;
    for(auto p : person_party)
        flow[p[1]][p[0]] = 1;
    for(auto p : person_club)
        flow[p[0]][p[1]] = 1;
    for(int club : clubs)
        flow[club][T] = 1;

    int F = max_flow(S, T);
    set<int> done;
    vector<string> result;
    for(auto p : person_club)
        if(flow[p[1]][p[0]] > 0){
        	if(!isalnum(revcomp[p[0]].back())) revcomp[p[0]].pop_back();
        	if(!isalnum(revcomp[p[1]].back())) revcomp[p[1]].pop_back();
            result.push_back(revcomp[p[0]] + " " + revcomp[p[1]]);
        }
    if(sz(result) < sz(clubs))
        cout << "Impossible.\n";
    else
    {
        for(string line : result)
            cout << line << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    scanf("%d\n", &t);
    while(t--)
    {
        cp();
        if(t) cout << endl;
    }
    return 0;
}
