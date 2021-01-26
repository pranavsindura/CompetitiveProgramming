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

int main()
{
    FASTIO;
    int v, e;
    cin >> v >> e;
    int c = 1;
    while(v || e)
    {
        // if(c != 1)
        //     cout << endl;
        vector<int> arr(v);
        for(int i = 0; i < v; i++)
            cin >> arr[i];
        ll total = 0;
        for(int x : arr)
            total += x;
        vector<vector<int>> adj(v + 1);
        vector<vector<int>> back(v + 1);
        for(int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            back[b].push_back(a);
        }
        cout << "Case #" << c++ << ":" << endl;
        int t;
        cin >> t;
        while(t--)
        {
            int x;
            cin >> x;
            vector<bool> vis(v + 1);
            fill(all(vis), false);
            queue<int> q;
            q.push(x);
            ll maxsum = total;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                vis[u] = true;
                maxsum -= arr[u - 1];
                for(int i = 0; i < sz(adj[u]); i++)
                {
                    if(!vis[adj[u][i]])
                        q.push(adj[u][i]), vis[adj[u][i]] = true;
                }
            }
            fill(all(vis), false);
            ll minsum = -arr[x - 1];
            q.push(x);
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                vis[u] = true;
                minsum += arr[u - 1];
                for(int i = 0; i < sz(back[u]); i++)
                {
                    if(!vis[back[u][i]])
                        q.push(back[u][i]), vis[back[u][i]] = true;
                }
            }
            cout << maxsum - minsum << endl;
        }
        cout<<endl;
        cin >> v >> e;
    }
    return 0;
}