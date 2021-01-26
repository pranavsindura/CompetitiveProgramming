#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
vector<int> arr[105];
int main()
{
    FASTIO;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	arr[b].pb(a);
    }
    for(int i=100;i>=0;i--)
    {
    	if(sz(arr[i]))
    	{
    		for(int x: arr[i])
    			cout<<x<<" "<<i<<endl;
    	}
    }
    return 0;
}