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
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<pii> op;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < k; i++)
    {
        auto mx = max_element(all(arr));
        auto mi = min_element(all(arr));
        if(*mx - *mi <= 1)
            break;
        int a = mx - arr.begin(), b = mi - arr.begin();
        arr[a]--, arr[b]++;
        op.pb(mp(a + 1, b + 1));
    }
    int mi = INT_MAX, mx = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        mi = min(mi, arr[i]);
        mx = max(mx, arr[i]);
    }
    cout << mx - mi << " " << sz(op) << endl;
    for(pii x : op)
        cout << x.ff << " " << x.ss << endl;
    return 0;
}