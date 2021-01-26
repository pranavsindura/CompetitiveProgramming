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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin >> t;
    map<pii, bool> vis;
    map<pii, int> ind;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int x = 0, y = 0;
        int start = INT_MIN, end = INT_MAX;
        bool f = false;
        vis.clear();
        ind.clear();
        vis[mp(0, 0)] = true;
        ind[mp(0, 0)] = -1;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'L')
                x--;
            else if(s[i] == 'R')
                x++;
            else if(s[i] == 'U')
                y++;
            else
                y--;
            if(vis.find(mp(x, y)) != vis.end())
            {
                if(!f)
                {
                    start = ind[mp(x, y)];
                    end = i;
                    f = true;
                }
                else
                {
                    if(end - start + 1 > i - ind[mp(x, y)] + 1)
                    {
                        start = ind[mp(x, y)];
                        end = i;
                    }
                }
                ind[mp(x, y)] = i;
            }
            else
            {
                vis[mp(x, y)] = true;
                ind[mp(x, y)] = i;
            }
        }
        if(f)
            cout << start + 2 << " " << end + 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}