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
int n, m;
int arr[105][105];

int rec(int st, int en)
{
    int len = en - st + 1;
    if(len & 1)
        return len;
    bool same = true;
    for(int j = 0; j < m; j++)
    {
        int down = len / 2;
        int up = down - 1;
        while(down < n && up >= 0)
        {
            if(arr[up][j] != arr[down][j])
                same = false;
            up--;
            down++;
        }
    }
    if(same)
        return rec(st + len / 2, en);
    else
        return len;
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    cout << rec(0, n - 1);
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