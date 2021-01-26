#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
vector<pii> w;
int main()
{
    FASTIO;
    int n, m, k, t;
    cin>>n>>m>>k>>t;
    for(int i=0;i<k;i++){
    	int a,b;
    	cin>>a>>b;
    	w.push_back(make_pair(a,b));
    }
    sort(all(w));
    while(t--)
    {
    	int a, b;
    	cin>>a>>b;
    	auto it = lower_bound(all(w), make_pair(a,b));
    	if(it == w.end())
    	{
    		int s = sz(w);
    		ll total = (a-1)*m + b - s;
    		total %= 3;
    		if(total == 0)
    			cout<<"Grapes\n";
    		else if(total == 1)
    			cout<<"Carrots\n";
    		else
    			cout<<"Kiwis\n";
    	}
    	else if(it->first == a && it->second == b)
    	{
    		cout<<"Waste\n";
    	}
    	else
    	{
    		int ind = it - w.begin();
    		ll total = (a-1)*m + b - ind;
    		total %= 3;
    		if(total == 0)
    			cout<<"Grapes\n";
    		else if(total == 1)
    			cout<<"Carrots\n";
    		else
    			cout<<"Kiwis\n";
    	}
    }
    return 0;
}