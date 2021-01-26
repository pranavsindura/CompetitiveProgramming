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
    string s;
    cin>>s;
    string t;
    int one=0;
    for(int i=0;i<ln(s);i++)
    {
    	if(s[i] == '1')
    		one++;
    	else
    		t += s[i];
    }
    int ind = -1;
    for(int i=0;i<ln(t);i++)
    {
    	if(t[i] == '2')
    	{
    		ind = i;
    		break;
    	}
    }
    string o;
    for(int i=0;i<one;i++)
    	o += "1";
    if(ind == -1)
    {
    	t += o;
    }
    else
    {
    	string temp = t;
    	t = "";
    	for(int i=0;i<ind;i++)
    	{
    		t += temp[i];
    	}
    	t += o;
    	for(int i=ind;i<ln(temp);i++)
    		t += temp[i];
    }
    cout<<t;
    return 0;
}