#include<bits/stdc++.h>
#define ll long long int
#define ld long double
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> arr(m);
    vector<int> cnt(26, 0);
    for(int &x : arr)
        cin >> x;
    for(char x: s)
    	cnt[x-'a']++;
    vector<bool> marked(m + 1, false);
    vector<char> ans(m);
    int c = 25;
    while(true)
    {
        bool found = false;
        vector<int> zero;
        for(int i = 0; i < m; i++)
            if(!marked[i] && arr[i] == 0)
                zero.pb(i), found = true;
        while(cnt[c] < sz(zero))
        {
            c--;
        }
        for(int pos : zero)
        {
            ans[pos] = char(97 + c), marked[pos] = true;
        }
        c--;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < sz(zero); j++)
                arr[i] -= abs(i - zero[j]);
        }
        if(!found)
            break;
    }
    for(auto x : ans)
    {
        cout << x;
    }
    cout << endl;
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