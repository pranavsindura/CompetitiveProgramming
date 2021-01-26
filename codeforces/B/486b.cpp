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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n)), make(m, vector<int>(n, 0)), ans(m, vector<int>(n, 1));
    bool possible = true;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 0)
            {
                for(int k = 0; k < m; k++)
                    ans[k][j] = 0;
                for(int k = 0; k < n; k++)
                    ans[i][k] = 0;
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int res = 0;
            for(int k = 0; k < m; k++)
                res = res | ans[k][j];
            for(int k = 0; k < n; k++)
                res = res | ans[i][k];
            make[i][j] = res;
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] != make[i][j])
                possible = false;
        }
    }
    if(possible)
    {
        cout << "YES\n";
        for(vector<int> a : ans)
        {
            for(int x : a)
                cout << x << " ";
            cout << endl;
        }
    }
    else
        cout << "NO";

    return 0;
}