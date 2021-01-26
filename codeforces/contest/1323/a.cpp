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

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	vector<int> arr(n);
    	for(int &x: arr)
    		cin>>x;
    	int odd=0,even=0;
    	for(int x:arr)
    	{
    		if(x%2)
    			odd++;
    		else
    			even++;
    	}
    	if(even)
    	{
    		cout<<1<<endl;
    		for(int i=0;i<n;i++)
    		{
    			if(arr[i]%2 == 0)
    			{
    				cout<<i+1<<endl;
    				break;
    			}
    		}
    	}
    	else if(odd >= 2)
    	{
    		cout<<2<<endl;
    		int c = 0;
    		for(int i=0;i<n;i++)
    		{
    			if(arr[i]%2 && c<2)
    			{
    				cout<<i+1<<" ";
    				c++;
    			}
    		}
    		cout<<endl;
    	}
    	else
    	{
    		cout<<-1<<endl;
    	}
    }
    return 0;
}