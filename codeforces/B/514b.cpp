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
    int n, a, b;
    cin>>n>>a>>b;
    vector<pii> arr(n);
    for(int i=0;i<n;i++)
    	cin>>arr[i].first>>arr[i].second;
    vector<bool> dead(n, false);
    int count=0;
    for(int i=0;i<n;i++)
    {
    	if(!dead[i])
    	{
    		count++;
    		for(int j=0;j<n;j++)
    		{
    			if(!dead[j])
    			{
                    int l = (arr[j].first-a)*(arr[i].second-b);

    				int r = (arr[i].first-a)*(arr[j].second-b);
    				if(l == r)
    					dead[j]=true;
    			}
    		}
    	}
    }
    cout<<count;
    return 0;
}