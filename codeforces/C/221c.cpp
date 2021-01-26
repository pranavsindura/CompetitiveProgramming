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
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n), v;
    for(int &x : arr)
        cin >> x, v.pb(x);
    sort(all(v));
    bool ok = true;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == v[i])
            continue;
        else
        {
            ok = false;
            for(int j = i + 1; j < n; j++)
            {
                if(arr[j] == v[i] && v[j] == arr[i])
                {
                    swap(arr[i], arr[j]);
                    ok = true;
                    break;
                }
            }
            break;
        }
    }
    for(int i = 1; i < n; i++)
    {
        if(arr[i - 1] > arr[i])
            ok = false;
    }
    cout << (ok ? "YES" : "NO");
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