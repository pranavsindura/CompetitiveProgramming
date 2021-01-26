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
    int n, m;
    cin >> n;
    map<int, int> cnt;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x, cnt[x]++;

    int ind = -1, very = INT_MIN, almost = INT_MIN;
    cin >> m;
    vector<int> b(m), c(m);
    for(int &x : b)
        cin >> x;
    for(int &x : c)
        cin >> x;
    for(int i = 0; i < m; i++)
    {
        int very_here = cnt[b[i]];
        int almost_here = cnt[c[i]];
        if(very_here > very || (very_here == very && almost_here > almost))
            ind = i, very = very_here, almost = almost_here;
    }
    cout << ind + 1;
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