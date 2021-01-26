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
    int sum, limit;
    cin>>sum>>limit;
    vector<int> arr;
    for(int i=limit;i>0;i--)
    {
    	int x = 1;
    	int temp = i;
    	while(!(temp&1))
    	{
    		x <<= 1;
    		temp >>= 1;
    	}
    	if(x <= sum)
    		arr.pb(i), sum -= x;
    }
    if(sum)
    	cout<<-1;
    else{
    	cout<<sz(arr)<<endl;
    	for(int x: arr)
    		cout<<x<<" ";
    }
    return 0;
}