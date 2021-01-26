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
    int n;
    cin>>n;
    vector<int> in(n), ex(n);
    for(int i=0;i<n;i++)
    	cin>>in[i];
    for(int i=0;i<n;i++)
    	cin>>ex[i];
    int i=0,j=0,c=0;
    vector<bool> fine(n+1, false);
    while(i<n && j<n)
    {
    	if(fine[in[i]])
    	{
    		i++;
    		continue;
    	}
    	if(in[i] == ex[j])
    		i++,j++;
    	else{
    		fine[ex[j]] = true;
    		c++,j++;
    	}
    }
    cout<<c;
    return 0;
}