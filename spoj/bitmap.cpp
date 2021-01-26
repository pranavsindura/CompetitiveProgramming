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

int arr[185][185];

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            for(int j = 0; j < m; j++)
            {
                arr[i][j] = s[j] - '0';
            }
        }
        vector<pii> wt;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j])
                    wt.pb(mp(i, j));
            }
        }
        int dis[185][185] = {0};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j])
                    continue;
                dis[i][j] = INT_MAX;
                for(int k = 0; k < sz(wt); k++)
                {
                    dis[i][j] = min(dis[i][j], abs(i - wt[k].ff) + abs(j - wt[k].ss));
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << dis[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}