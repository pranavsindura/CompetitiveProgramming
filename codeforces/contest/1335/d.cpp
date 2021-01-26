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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
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
    int grid[9][9];
    for(int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < 9; j++)
        {
            grid[i][j] = s[j] - '0';
        }
    }
    vector<bool> marked(10, false);
    vector<pii> v =
    {
        {0, 0}, {3, 1}, {6, 2},
        {1, 3}, {4, 4}, {7, 5},
        {2, 6}, {5, 7}, {8, 8}
    };
    for(pii x : v)
    {
        for(int i = 1; i <= 9; i++)
        {
            if(grid[x.ff][x.ss] != i)
            {
                grid[x.ff][x.ss] = i;
                marked[i] = true;
                break;
            }
        }
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cout<<grid[i][j];
        cout<<endl;
    }

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