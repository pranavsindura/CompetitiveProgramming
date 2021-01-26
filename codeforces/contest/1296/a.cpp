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
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int &i : arr)	cin >> i;
        int eve=0,odd=0;
    	int sum=0;
    	for(int x: arr)
    	{
    		if(x%2)
    			odd++;
    		else
    			eve++;
    		sum += x;
    	}
    	if(sum%2 == 0)
    	{
    		if(eve && odd)
    			cout<<"YES\n";
    		else
    			cout<<"NO\n";
    	}
    	else
    	{
    		cout<<"YES\n";
    	}
    }
    return 0;
}