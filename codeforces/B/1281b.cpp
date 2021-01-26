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
    	string a,b;
    	cin>>a>>b;
    	if(a<b)
    	{
    		cout<<a<<endl;
    		continue;
    	}
    	string temp = a;
    	sort(all(temp));
    	bool f = false;
    	for(int i=0;i<ln(a);i++)
    	{
    		if(a[i] != temp[i])
    		{
    			for(int j=ln(a)-1;j>i;j--)
    			{
    				if(a[j] == temp[i])
    				{
    					char x = a[j];
    					a[j]=a[i];
    					a[i]=x;
    					f=true;
    					break;
    				}
    			}
    			break;
    		}
    	}
    	if(f)
    	{
    		if(a<b)
    			cout<<a<<endl;
    		else
    			cout<<"---\n";
    	}
    	else
    		cout<<"---\n";
    }
    return 0;
}