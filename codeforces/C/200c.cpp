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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

struct team
{
    string name;
    int points, scored, missed;
    team(): name(""), points(0), scored(0), missed(0) {}
    team(string name, int points, int scored, int missed): name(name), points(points),
        scored(scored), missed(missed) {}
    const bool operator<(const team &u)const
    {
        // more points first
        if(points != u.points)
            return points > u.points;
        // more scored-missed difference first
        if(scored - missed != u.scored - u.missed)
            return scored - missed > u.scored - u.missed;
        // more goals scored first
        if(scored != u.scored)
            return scored > u.scored;
        // smaller name first
        return name < u.name;
    }
};

void cp()
{
    map<string, team> team_data;
    map<string, int> games_played;
    for(int i = 0; i < 5; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        int sa = c[0] - '0', sb = c[2] - '0';
        games_played[a]++, games_played[b]++;

        if(sa < sb)
            swap(sa, sb), swap(a, b);

        int pa = 0, pb = 0;
        if(sa > sb) // team a won
            pa = 3;
        else // draw
            pa = 1, pb = 1;

        team_data[a].points += pa, team_data[a].scored += sa, team_data[a].missed += sb;
        team_data[b].points += pb, team_data[b].scored += sb, team_data[b].missed += sa;
    }

    vector<team> teams;
    for(pair<string, team> u : team_data)
        u.ss.name = u.ff, teams.pb(u.ss);

    string me = "BERLAND", other;
    for(team u : teams)
        if(games_played[u.name] == 2 && u.name != me)
            other = u.name;

    sort(all(teams));

    auto check = [&](int v, int w)
    {
        vector<team> temp = teams;
        for(team &u : temp)
        {
            if(u.name == me)
                u.points += 3, u.scored += v, u.missed += w;
            else if(u.name == other)
                u.missed += v, u.scored += w;
        }

        sort(all(temp));
        // Did i win?
        return (temp[0].name == me || temp[1].name == me);
    };

    pi best = {2000, 1000};

    for(int x = 1; x <= 20; x++)
        for(int y = 0; y < x; y++)
            if(check(x, y))
                if((x - y < best.ff - best.ss) || ((x - y == best.ff - best.ss) && (y < best.ss)))
                    best = {x, y};
    
    if(best.ff > 20)
        cout << "IMPOSSIBLE\n";
    else
        cout << best.ff << ":" << best.ss << endl;
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