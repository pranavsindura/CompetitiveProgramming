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

int colr[5005], colc[5005];
int lastr[5005], lastc[5005];
void cp()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= q; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        if(t == 1)
            lastr[a] = i, colr[a] = b;
        else
            lastc[a] = i, colc[a] = b;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout << (lastr[i] > lastc[j] ? colr[i] : colc[j]) << " \n"[j == m-1];
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