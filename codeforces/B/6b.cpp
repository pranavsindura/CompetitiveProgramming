#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vpii vector<pii>
#define vll vector<ll>
const double PI = acos(-1.0);
using namespace std;
bool valid(int i, int j, int n, int m)
{
    if(i>=0 && i<n && j >=0 && j < m)
        return true;
    else
        return false;
}
int main()
{
    FASTIO;
    int n, m;
    char p;
    cin>>n>>m>>p;
    vector<vector<char>> arr(n, vector<char>(m, '.'));
    bool vis[26];
    memset(vis, false, sizeof(vis));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    int count = 0;
    vis[p-'A'] = true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == p)
            {
                if(valid(i-1,j,n,m))
                {
                    if(!vis[arr[i-1][j]-'A']   && arr[i-1][j] != '.')
                    {
                        count++;
                        vis[arr[i-1][j]-'A'] = true;
                    }
                }
                if(valid(i+1,j,n,m))
                {
                    if(!vis[arr[i+1][j]-'A'] && arr[i+1][j] != '.')
                    {
                        count++;
                        vis[arr[i+1][j]-'A'] = true;
                    }
                }
                if(valid(i,j-1,n,m))
                {
                    if(!vis[arr[i][j-1]-'A'] && arr[i][j-1] != '.')
                    {
                        count++;
                        vis[arr[i][j-1]-'A'] = true;
                    }
                }
                if(valid(i,j+1,n,m))
                {
                    if(!vis[arr[i][j+1]-'A'] && arr[i][j+1] != '.')
                    {
                        count++;
                        vis[arr[i][j+1]-'A'] = true;
                    }
                }
            }
        }
    }
    cout<<count;
    return 0;
}