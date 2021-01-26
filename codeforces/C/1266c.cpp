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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 1));
    if(n == 1 && m == 1)
    {
        cout << 0 << endl;
        return;
    }

    if(n == 1)
    {
        int num = 2;
        for(int j = 0; j < m; j++, num++)
            arr[0][j] = num;
    }
    else if(m == 1)
    {
        int num = 2;
        for(int i = 0; i < n; i++, num++)
            arr[i][0] = num;
    }
    else
    {
        int num = 2;
        for(int i = 0; i < n; i++, num++)
            for(int j = 0; j < m; j++)
                arr[i][j] *= num;
        for(int j = 0; j < m - 1; j++, num++)
            for(int i = 0; i < n; i++)
                arr[i][j] *= num;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout << arr[i][j] << " \n"[j == m - 1];
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