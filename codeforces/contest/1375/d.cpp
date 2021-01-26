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

bool sorted(vector<int> &arr)
{
    for(int i = 0; i < sz(arr) - 1; i++)
        if(arr[i] > arr[i + 1])
            return false;
    return true;
}

int get_mex(vector<int> &arr)
{
    bool used[1005];
    clr(used, false);
    for(int x : arr)
        used[x] = true;
    for(int i = 0; i <= sz(arr); i++)
        if(!used[i])
            return i;
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    vector<int> ops;
    while(!sorted(arr))
    {
        int mex = get_mex(arr);
        if(mex == n)
        {
            for(int i = 0; i < n; i++)
            {
                if(arr[i] != i)
                {
                    arr[i] = mex;
                    ops.pb(i + 1);
                    break;
                }
            }
        }
        else
        {
            arr[mex] = mex;
            ops.pb(mex + 1);
        }
    }

    cout << sz(ops) << endl;
    for(int x : ops)
        cout << x << " ";
    cout << endl;
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