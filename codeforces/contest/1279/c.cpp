#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vpii vector<pii>
#define vll vector<ll>
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
    	int n, m;
    	cin>>n>>m;
    	vector<int> a(n), b(m);
    	map<int, int> ind;
    	for(int i=0;i<n;i++)
    		cin>>a[i], ind[a[i]]=i;
    	for(int i=0;i<m;i++)
    		cin>>b[i];
    	int l=0, sz=n,time=0, pre=0 ;
    	for(int i=0;i<m;i++)
    	{
    		if(ind[b[i]]<=l)
    		{
    			pre++;
    			time += 1;
    		}
    		else
    		{
    			l = ind[b[i]]-1-pre;
    			time += 2*(l+1-pre)+1;
    			pre=0;
    		}
    	}
    	cout<<time<<endl;
    }
    return 0;
}