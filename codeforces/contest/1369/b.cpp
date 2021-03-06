#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    reverse(all(s));
    stack<int> st;
    for(int i=0;i<n;i++)
    {
    	int num = s[i]-'0';
    	if(st.empty())
    		st.push(num);
    	else
    	{
    		if(num == 1)
    		{
    			bool rem = false;
    			while(!st.empty() && st.top() == 0)
    			{
    				rem = true;
    				st.pop();
    			}
    			if(rem)
    				st.push(0);
    			else
    				st.push(num);
    			// dont put 1
    		}
    		else
    		{
    			st.push(num);
    		}
    	}
    }
    string ans;
    while(!st.empty())
    	ans += char(48+st.top()), st.pop();
    cout<<ans<<endl;;
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