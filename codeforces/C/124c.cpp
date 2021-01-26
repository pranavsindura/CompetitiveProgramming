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
    string s;
    cin >> s;
    int n = ln(s);
    int cnt[26] = {0};
    for(char x : s)
        cnt[x - 'a']++;
    vector<pi> freq;
    for(int i = 0; i < 26; i++)
        if(cnt[i])
            freq.pb({cnt[i], i});
    sort(all(freq));

    vector<int> colour(n + 1, 0);
    int c = 1;
    colour[1] = 1;
    for(int i = 2; i <= n; i++)
    {
    	if(colour[i])
    		continue;
        bool any = false;
        int col = 0;
        for(int j = i; j <= n; j += i)
        {
            if(colour[j])
            {
                any = true;
                col = colour[j];
            }
        }
        if(any)
        {
        	for(int j = i; j <= n; j += i)
            {
                colour[j] = col;
            }
        }
        else
        {
            ++c;
            for(int j = i; j <= n; j += i)
            {
                colour[j] = c;
            }
        }
    }
    bool ok = true;
    vector<char> ans(n+1);
    for(int i=1;i<=c;i++)
    {
    	int cnt_colour = 0;
    	for(int j=1;j<=n;j++)
    		if(colour[j] == i)
    			cnt_colour++;
    	int pos = 0;
    	sort(all(freq));
    	while(pos<sz(freq) && freq[pos].ff < cnt_colour)
    		pos++;
    	if(pos == sz(freq))
    	{
    		ok = false;
    		break;
    	}
    	freq[pos].ff -= cnt_colour;
    	for(int j=1;j<=n;j++)
    	{
    		if(colour[j] == i)
    		{
    			ans[j] = char(97 + freq[pos].ss);
    		}
    	}
    }
    if(ok)
    {
    	cout<<"YES\n";
    	for(int i=1;i<=n;i++)
    		cout<<ans[i];
    }
    else
    	cout<<"NO";
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