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
    int seg[10]={6,2,5,5,4,5,6,3,7,6};
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int div3=0,div2=0;
    	while(n)
    	{
    		if(n==2)
    		{
    			div2++;
    			break;
    		}
    		else if(n==3)
    		{
    			div3++;
    			break;
    		}
    		else if(n==4)
    		{
    			div2+=2;
    			break;
    		}
    		else if(n == 5)
    		{
    			div3++;
    			div2++;
    			break;
    		}
    		else if(n == 6)
    		{
    			div2+=3;
    			break;
    		}
    		n -= 2;
    		div2++;
    	}
    	for(int i=0;i<div3;i++)
    		cout<<"7";
    	for(int i=0;i<div2;i++)
    		cout<<"1";
    	cout<<endl;
    }
    return 0;
}