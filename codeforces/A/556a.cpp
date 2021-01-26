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
    // int z = 0, o = 0;
    // for(char x : s)
    //     if(x == '0')
    //         z++;
    //     else
    //         o++;
    // int mn = min(z, o);
    // cout << n - mn * 2;
    stack<char> st;
    for(char x: s)
    {
    	if(st.empty())
    		st.push(x);
    	else
    	{
    		if(st.top() != x)
    			st.pop();
    		else
    			st.push(x);
    	}
    }
    cout<<sz(st);
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}