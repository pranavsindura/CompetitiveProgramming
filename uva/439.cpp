#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(a) cout<<a.first<<" "<<a.second<<endl;
const double PI = acos(-1.0);
using namespace std;

bool valid(int i, int j)
{
	if(i>=0 && i<8 && j>=0&&j<8)
		return true;
	else
		return false;
}

int main()
{
    FASTIO;
    string x, y;
    while(cin>>x>>y)
    {
    	
    	pii a = make_pair((x[1]-'0')-1,x[0]-'a'), b = make_pair((y[1]-'0')-1,y[0]-'a');
    	bool vis[8][8];
    	memset(vis, false, sizeof(vis));
    	queue<pii> q;
    	q.push(a);
    	int depth[8][8] = {0};
    	depth[a.first][a.second] = 0;
    	int dx[] = {1,-1, 1,-1, 2, 2,-2,-2};
    	int dy[] = {2, 2,-2,-2, 1,-1, 1,-1};
    	while(!q.empty())
    	{
    		pii u = q.front();
    		q.pop();
    		vis[u.first][u.second] = true;
    		for(int i=0;i<8;i++)
    		{
    			if(valid(u.first+dy[i], u.second+dx[i]) && !vis[u.first+dy[i]][u.second+dx[i]])
    			{
    				vis[u.first+dy[i]][u.second+dx[i]] = true;
    				q.push(make_pair(u.first+dy[i], u.second+dx[i]));
    				depth[u.first+dy[i]][u.second+dx[i]] = depth[u.first][u.second] + 1;
    			}
    		}
    	}
    	cout<<"To get from "<<x<<" to "<<y<<" takes "<<depth[b.first][b.second]<<" knight moves.\n";
    }
    return 0;
}