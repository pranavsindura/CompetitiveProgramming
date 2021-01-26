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

bool subseq(string s, string t, int n, int m)
{
	if(m == 0)
		return true;
	if(n==0)
		return false;

	if(s[n-1] == t[m-1])
		return subseq(s,t,n-1,m-1);
	else
		return subseq(s,t,n-1,m);
}

int main()
{
    FASTIO;
    string s,t;
    cin>>s>>t;
    //make t from s
    bool allfound=true;
    int hashs[26]={0}, hasht[26]={0};
    for(char x: s)
    	hashs[x-'a']++;
    for(char x: t)
    	hasht[x-'a']++;
    for(int i=0;i<ln(t);i++)
    {
    	if(!hashs[t[i]-'a'] || (hashs[t[i]-'a'] < hasht[t[i]-'a']))
    		allfound=false;
    }

    if(!allfound || (ln(s) < ln(t)))
    {
    	cout<<"need tree";
    }
    else
    {
    	if(subseq(s,t,ln(s), ln(t)))
    	{
    		cout<<"automaton";
    	}
    	else
    	{
    		if(ln(s) == ln(t))
    			cout<<"array";
    		else
    			cout<<"both";
    	}
    }
    return 0;
}