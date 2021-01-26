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

int main()
{
    FASTIO;
    int n, m;
    cin>>n>>m;
    vector<string> s, t;
    for(int i=0;i<n;i++)
    {
    	string x;
    	cin>>x;
    	s.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
    	string x;
    	cin>>x;
    	t.push_back(x);
    }
    int q;
    cin>>q;
    while(q--)
    {
    	int a;
    	cin>>a;
    	a--;
    	int remn = a%n, remm = a%m;
    	cout<<s[remn]<<t[remm]<<endl;
    }
    return 0;
}