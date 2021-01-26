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

void cp(int n, int k)
{
    vector<int> time_taken(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> time_taken[i];
    vector<vector<pi>> reach(100);
    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;
    cin.ignore();
    for(int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> floor;
        while(!ss.eof())
        {
            int a;
            ss >> a;
            floor.pb(a);
        }
        for(int j = 0; j < sz(floor); j++)
        {
            if(floor[j] == 0)
            {
                pq.push({0, {0, i}});
            }
            for(int l = 0; l < sz(floor); l++)
            {
                if(j == l)
                    continue;
                reach[floor[j]].pb({floor[l], i});
            }
        }
    }
    vector<int> dist(100, INT_MAX);
    vector<bool> vis(100, false);
    if(sz(pq))
        dist[0] = 0;
    while(!pq.empty())
    {
        // dbg(sz(pq));
        pair<int, pi> node = pq.top();
        pq.pop();
        int at = node.ss.ff;
        int ele = node.ss.ss;
        int time_so_far = node.ff;
        if(dist[at] < time_so_far)
            continue;

        for(pi node2 : reach[at])
        {
            int at2 = node2.ff;
            int ele2 = node2.ss;
            int cost = 0;
            if(ele != ele2)
                cost = abs(at2 - at) * time_taken[ele2] + 60;
            else
                cost = abs(at2 - at) * time_taken[ele];
            if(dist[at2] > dist[at] + cost)
            {
                dist[at2] = dist[at] + cost;
                pq.push({dist[at2], {at2, ele2}});
            }
        }
    }

    if(dist[k] == INT_MAX)
        cout << "IMPOSSIBLE";
    else
        cout << dist[k];
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    int n, k;
    while(cin >> n >> k)
    {
        cp(n, k);
        cout << endl;
    }
    return 0;
}