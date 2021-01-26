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

class PerfectPermutation
{
public:
    int reorder(vector<int> arr)
    {
        int cnt = 0;
        int n = sz(arr);
        vector<bool> vis(n);
        for(int i = 0; i < n; i++)
        {
            if(vis[i])
                continue;
            cnt++;
            int pos = i;
            while(!vis[pos])
                vis[pos] = true, pos = arr[pos];
        }
        if(cnt == 1)
            cnt = 0;
        return cnt;
    }
};

int main()
{
    PerfectPermutation p;
    vector<int> inp = 
{4, 2, 6, 0, 3, 5, 9, 7, 8, 1}

;
    cout << p.reorder(inp) << endl;
}