/*input
10 10
ddorannorz
mdrnzqvqgo
gdtdjmlsuf
eoxbrntqdp
hribwlslgo
ewlqrontvk
nxibmnawnh
vxiwdjvdom
hyhhewmzmp
iysgvzayst
*/
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
int n, m;
bool removed[105];
string arr[105];

bool is_sorted(vector<string> &arr)
{
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    vector<string> res(n);
    int count = 0;
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            res[i].pb(arr[i][j]);
        }
        if(is_sorted(res))
        {
            //ok
        }
        else
        {
            count++;
            for(int i = 0; i < n; i++)
            {
                res[i].pop_back();
            }
        }
    }
    cout << count;
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