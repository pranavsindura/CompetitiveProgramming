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
    int t;
    cin>>t;
    while(t--)
    {
    	int n, x;
    	cin>>n;
    	set<int, greater<int>> s;
    	for(int i=0;i<n;i++)
    	{
    		cin>>x;
    		if(x%2)
    			continue;
    		s.insert(x);
    	}
    	int c=0;
    	while(s.size())
    	{
    		x = *s.begin();
    		s.erase(s.begin());
    		x /= 2;
    		c++;
    		if(x%2 == 0)
    			s.insert(x);
    	}
    	cout<<c<<endl;
    }
    return 0;
}