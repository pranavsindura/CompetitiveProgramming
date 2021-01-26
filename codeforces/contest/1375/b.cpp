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
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    auto valid = [&](int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    };
    bool ok = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int cnt = 0;
            if(valid(i + 1, j))
                cnt++;
            if(valid(i, j + 1))
                cnt++;
            if(valid(i - 1, j))
                cnt++;
            if(valid(i, j - 1))
                cnt++;

            if(arr[i][j] == 0)
            {
                arr[i][j] = cnt;
            }
            else
            {
                if(arr[i][j] > cnt)
                    ok = false;
                else
                    arr[i][j] = cnt;
            }
        }
    }
    if(ok)
    {
        cout << "YES\n";
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cout << arr[i][j] << " \n"[j == m - 1];
    }
    else
        cout << "NO\n";
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