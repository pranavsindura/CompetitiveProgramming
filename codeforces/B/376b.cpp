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
    int n,m;
    cin>>n>>m;
    vector<int> owe(n+1, 0);
    for(int i=0;i<m;i++)
    {
    	int a,b,c;
    	cin>>a>>b>>c;
    	owe[a] -= c;
    	owe[b] += c;
    }
    ll sum=0;
    for(int x: owe)
    	if(x<0)
    		sum+=x;
    sum *= -1;
    cout<<sum;
    return 0;
}