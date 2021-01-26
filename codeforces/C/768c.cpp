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
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
using namespace std;
map<vector<int>, int> pos;
void cp()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    sort(all(arr));
    int rem = 0;
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j % 2 == 0)
                arr[j] ^= x;
        }
        sort(all(arr));
        if(pos.count(arr))
        {
            rem = (k - i - 1) % (pos[arr] - i);
            break;
        }
        pos[arr] = i;
    }
    for(int i = 0; i < rem; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j % 2 == 0)
                arr[j] ^= x;
        }
        sort(all(arr));
    }
    int mx = *max_element(all(arr));
    int mn = *min_element(all(arr));
    cout << mx << " " << mn << endl;
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