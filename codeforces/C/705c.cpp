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
#define endl '\n'
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);

void cp()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> unread(n + 1);
    vector<int> pos(q + 1, -1);
    vector<bool> read(q + 1, false);
    int total = 0;
    int notif = 0;
    int last = 1;
    for(int i = 1; i <= q; i++)
    {
        int t, x;
        cin >> t >> x;
        if(t == 1)
        {
            total++;
            unread[x].pb(++notif);
        }
        else if(t == 2)
        {
            for(int p : unread[x])
            {
                if(!read[p])
                    total--, read[p] = true;
            }
            unread[x].clear();
        }
        else
        {
            for(; last <= x; last++)
            {
                if(!read[last])
                    total--, read[last] = true;
            }
        }
        cout << total << endl;
    }
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