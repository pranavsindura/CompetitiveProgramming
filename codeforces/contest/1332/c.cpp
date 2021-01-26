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
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

void cp()
{
    int n, k, c = 0;
    cin >> n >> k;
    string s, temp;
    cin >> s;
    vector<string> part;
    for(int i = 0; i < n; i++)
    {

        temp += s[i], c++;
        if(c==k)
        {
        	part.pb(temp);
        	temp = "";
        	c=0;
        }
    }
    int total = 0;
    int nk = n/k;
    for(int i=0;i<(k+1)/2;i++)
    {
    	int l = i, r=k-i-1;
    	int ans=0;
    	int h[26]={0};
    	for(int j=0;j<sz(part);j++){
    		h[part[j][l]-'a']++;
    		h[part[j][r]-'a']++;
    	}
    	int mx = INT_MIN;
    	char ch;
    	for(int i=0;i<26;i++)
    	{
    		if(h[i] > mx)
    		{
    			mx = h[i];
    			ch = char(97+i);
    		}
    	}

    	for(int j=0;j<sz(part);j++)
    	{
    		if(part[j][l] != ch){
    			ans++;
    			// part[j][l] = ch;
    		}
    	}
    	for(int j=0;j<sz(part);j++)
    	{
    		if(part[j][r] != ch){
    			ans++;
    			// part[j][r] = ch;
    		}
    	}
    	if(l==r)
    		ans /= 2;
    	// cout<<i<<" "<<ch<<" "<<ans<<endl;
    	total += ans;
    }
   	cout<<total<<endl;
   	// for(string x: part)
   	// 	cout<<x<<endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}