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

typedef vector<int> row;
typedef vector<row> matrix;


matrix solve(int k)
{
    // H1 = [1]
    // Hn+1 = [Hn  Hn]
    //        [Hn -Hn]
    if(k == 0)
        return matrix(1, row(1, 1));
    else
    {
        matrix a = solve(k - 1);

        int n = sz(a);
        int m = sz(a[0]);

        matrix res(2 * n, row(2 * m));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                res[i][j] = a[i][j];

        for(int i = n; i < 2 * n; i++)
            for(int j = 0; j < m; j++)
                res[i][j] = a[i - n][j];

        for(int i = 0; i < n; i++)
            for(int j = m; j < 2 * m; j++)
                res[i][j] = a[i][j - n];

        for(int i = n; i < 2 * n; i++)
            for(int j = m; j < 2 * m; j++)
                res[i][j] = -a[i - n][j - n];

        return res;
    }
}

void cp()
{
    int k;
    cin >> k;
    matrix a = solve(k);
    int n = sz(a);
    int m = sz(a[0]);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << (a[i][j] > 0 ? '*' : '+');
        cout << endl;
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