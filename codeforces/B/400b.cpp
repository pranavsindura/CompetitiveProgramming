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
    int n, m;
    cin>>n>>m;
    vector<vector<char>> arr(n, vector<char>(m, '.'));
    for(int i=0;i<n;i++)
    {
    	string s;
    	cin>>s;
    	for(int j=0;j<s.length();j++)
    		arr[i][j] = s[j];
    }
    int ans = 0;
    vector<int> pos(n);
    vector<bool> done(n, false);
    bool ok = true;
    for(int i=0;i<n;i++)
    {
    	int posg=-1, poss=-1;
    	for(int j=0;j<m;j++)
    	{
    		if(arr[i][j] == 'G'){
    			posg = j;
    			break;
    		}
    	}
    	for(int j=0;j<m;j++)
    	{
			if(arr[i][j] == 'S'){
    			poss=j;
    			break;
			}
    	}
    	if(posg > poss)
    		ok = false;
    	else
    		pos[i] = posg-poss;
    }
    if(!ok)
    {
    	cout<<-1;
    	return 0;
    }
    while(true)
    {
    	int mind = INT_MAX;
    	for(int i=0;i<n;i++)
    	{
    		if(!done[i])
    			mind = min(mind, pos[i]);
    	}
    	if(mind == INT_MAX)
    		break;
    	for(int i=0;i<n;i++)
    	{
    		if(!done[i])
    		{
    			pos[i] -= mind;
    			if(pos[i] == 0)
    				done[i] = true;
    		}
    	}
    	ans++;
    }
    cout<<ans;
    return 0;
}