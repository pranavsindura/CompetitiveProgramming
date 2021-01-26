#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.0000000011
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);
int MAXN = 100005;
vector<int> x(100005, 0), h(100005, 0);
int fell[100005][3]={0};
//0 not cut, 1 left, 2 right
int n;
int m = INT_MIN;

int main()
{
    FASTIO;
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>x[i]>>h[i];
    int count = 1;
    int last = x[0];
    x[n] = INT_MAX;
    for(int i=1;i<n;i++)
    {
    	if(x[i]-h[i] > last)
    	{
    		count++;
    		last = x[i];
    	}
    	else if(x[i]+h[i] < x[i+1])
    	{
    		count++;
    		last = x[i]+h[i];
    	}
    	else
    	{
    		last=x[i];
    	}
    }
    cout<<count;
    return 0;
}