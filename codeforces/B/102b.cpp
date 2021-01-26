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
    string s;
    cin>>s;
    ll sum=0;
    int c=0;
    for(int i=0;i<s.length();i++)
    	sum += s[i]-'0';
    if(s.length()>1)
    	c=1;
    while(sum/10 != 0)
    {
    	ll temp = 0;
    	while(sum)
    	{
    		temp += sum%10;
    		sum /= 10;
    	}
    	sum = temp;
    	c++;
    }
    cout<<c;
    return 0;
}