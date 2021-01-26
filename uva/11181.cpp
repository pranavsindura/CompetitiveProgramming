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
int n, r;
double arr[25], ans[25];
bool vis[25];
double total;
void solve(int i, int picked)
{
    if(i == n)
    {
        if(picked == r)
        {
            double here = 1;
            for(int j = 0; j < n; j++)
            {
                if(vis[j])
                {
                    // cout << j + 1 << " ";
                    here *= arr[j];
                }
                else
                    here *= (1 - arr[j]);
            }
            // cout << ": " << here << endl;
            for(int j = 0; j < n; j++)
            {
                if(vis[j])
                    ans[j] += here;
            }
            total += here;
        }
    }
    else
    {
        if(picked > r)
            return;
        solve(i + 1, picked);
        vis[i] = true;
        solve(i + 1, picked + 1);
        vis[i] = false;
    }

}

void cp()
{
    int test_case = 1;
    while(true)
    {
        cin >> n >> r;
        if(!n && !r)
            break;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            ans[i] = 0;
        }
        total = 0;
        solve(0, 0);
        cout << "Case " << test_case << ":\n";
        for(int i = 0; i < n; i++)
        {
            cout << setprecision(6) << fixed << ans[i] / total << endl;
        }
        test_case++;
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