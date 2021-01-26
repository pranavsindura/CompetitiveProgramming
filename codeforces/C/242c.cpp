#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
int MAXN = (int)1e9;
bool valid(int i, int j)
{
    if(i > 0 && i <= MAXN && j > 0 && j <= MAXN)
        return true;
    else return false;
}
int main()
{
    FASTIO;
    pii a, b;
    cin >> a.first >> a.second >> b.first >> b.second;
    int n;
    cin >> n;
    map<int, set<int>> allowed;
    for(int i = 0; i < n; i++)
    {
        int r, x, y;
        cin >> r >> x >> y;
        for(int j = x; j <= y; j++)
            allowed[r].insert(j);
    }
    map<pii, int> depth;
    queue<pii> q;
    q.push(a);
    depth[a] = 0;
    bool found = false;
    while(!q.empty())
    {
        pii x = q.front();
        q.pop();
        int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
        for(int i = 0; i < 8; i++)
        {
            if(
                valid(x.first + dy[i], x.second + dx[i]) &&
                depth[mp(x.first + dy[i], x.second + dx[i])] == 0 &&
                allowed[x.first + dy[i]].find(x.second + dx[i]) != allowed[x.first + dy[i]].end()
            )
            {
                q.push(mp(x.first + dy[i], x.second + dx[i])), depth[mp(x.first + dy[i], x.second + dx[i])] = depth[x] + 1;
                if(x.first + dy[i] == b.first && x.second + dx[i] == b.second)
                {
                    found = true;
                    break;
                }
            }
        }
    }
    if(found)
        cout << depth[b];
    else
        cout << -1;
    return 0;
}