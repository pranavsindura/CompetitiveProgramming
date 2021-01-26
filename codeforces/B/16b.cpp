#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> arr(m);
    for(int i=0;i<m;i++)
    	cin>>arr[i].first>>arr[i].second;
    sort(all(arr), [](pair<int,int> a, pair<int,int> b){return a.second > b.second;});
    int ans=0, taken = 0;
    for(int i=0;i<m;i++)
    {
    	if(taken<n)
    	{
    		int takenow = min(n-taken, arr[i].first);
    		ans += takenow*arr[i].second;
    		taken += takenow;
    	}
    }
    cout<<ans;
    return 0;
}