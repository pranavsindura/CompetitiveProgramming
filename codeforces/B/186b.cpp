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

double f(vector<int> a,int k, int t1, int t2)
{
	double ans = a[0]*t1*1.0;
    	double kp = k*1.0;
    	ans -= kp*ans/100;
    	ans += a[1]*t2*1.0;
    	return ans;
}

int main()
{
    FASTIO;
    int n, t1, t2, k;
    cin>>n>>t1>>t2>>k;
    vector<vector<int>> arr(n, vector<int>(2,0));
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i][0]>>arr[i][1];
    	sort(all(arr[i]));
    }
    vector<double> h(n);
    for(int i=0;i<n;i++)
    {
    	int a = arr[i][0], b=arr[i][1];
    	h[i] = max(f({a,b}, k, t1, t2), f({b,a}, k, t1, t2));
   	}
    map<double,set<int>> m;
    for(int i=0;i<n;i++)
    {
    	m[h[i]].insert(i+1);
    }
    
    for(auto it = m.rbegin(); it != m.rend();it++)
    {
    	for(int x: it->second)
    	{
    		cout<<fixed<<setprecision(2)<<x<<" "<<it->first<<endl;
    	}
    }
    return 0;
}