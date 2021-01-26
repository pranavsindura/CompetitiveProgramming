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
#define dbg(x) cout<<#x<<": "<<x<<endl
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
    string s;
    cin >> n >> s;
    set<int> one, zero;
    int cnt = 0;
    vector<int> ans(n);
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0')
        {
            if(one.empty())
            {
                // start a new zero
                cnt++;
                ans[i] = cnt;
                zero.insert(cnt);
            }
            else
            {
                int p = *one.begin();
                one.erase(one.begin());
                ans[i] = p;
                zero.insert(p);
            }
        }
        else
        {
            if(zero.empty())
            {
                // start a new one
                cnt++;
                ans[i] = cnt;
                one.insert(cnt);
            }
            else
            {
                int p = *zero.begin();
                zero.erase(zero.begin());
                ans[i] = p;
                one.insert(p);
            }
        }
    }
    cout << cnt << endl;
    for(int x : ans)
        cout << x << " ";
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