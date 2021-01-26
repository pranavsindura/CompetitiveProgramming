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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);

void cp()
{
    int n, m, q;
    cin >> n >> m >> q;
    int arr[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    int row_num[n], col_num[m];
    for(int i = 0; i < n; i++)
        row_num[i] = i;
    for(int i = 0; i < m; i++)
        col_num[i] = i;
    while(q--)
    {
        char t;
        int x, y;
        cin >> t >> x >> y;
        x--, y--;
        if(t == 'c')
        {
            swap(col_num[x], col_num[y]);
        }
        else if(t == 'r')
        {
            swap(row_num[x], row_num[y]);
        }
        else
        {
            cout << arr[row_num[x]][col_num[y]] << endl;
        }
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