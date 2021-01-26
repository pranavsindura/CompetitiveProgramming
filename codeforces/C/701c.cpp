#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
#define eps 0.000000001
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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    string s;
    cin >> n >> s;
    set<char> se(all(s));
    map<char, int> m;
    int distinct = sz(se);
    int i = 0, j = 0;
    m[s[0]]++;
    int ans = n;
    while(j < n)
    {
        if(sz(m) < distinct){
            j++;
        	m[s[j]]++;
        }
        else
        {
            m[s[i]]--;
            if(!m[s[i]])
                m.erase(s[i]);
            ans = min(ans, j - i + 1);
            i++;
        }
    }
    cout<<ans;
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