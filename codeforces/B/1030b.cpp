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
    int n,d,m;
    cin>>n>>d>>m;
    vector<pii> arr(m);
    for(int i=0;i<m;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	arr[i] = mp(a,b);
    }
    for(int i=0;i<m;i++)
    {
    	int x = arr[i].ff, y = arr[i].ss;
    	if((x-y <= d) && (x-y >= -d) && (x+y >= d) && (x+y <= 2*n - d))
    		cout<<"YES\n";
    	else
    		cout<<"NO\n";
    }
    return 0;
}