#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    int n, k;
    cin >> n >> k;
    k--;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    // Find Smallest Element, Find last occurance
    int mi = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= arr[mi])
            mi = i;
    }
    ll mi_e = arr[mi];

    // If occurance is present before k, pick it! Still Last occurance
    for(int i = 0; i <= k; i++)
    {
        if(arr[i] == mi_e)
            mi = i;
    }
    // Shift All elements by minimum element
    for(ll &x : arr)
        x -= mi_e;

    // Holds the value to be put in at min_element index
    // Traverse from left to right to reach k position and subtract 1 from elements, add all that to num
    ll num = mi_e * 1LL * n;
    if(k < mi)
    {
        for(int i = mi + 1; i < n; i++)
            arr[i]--, num++;
        for(int i = 0; i <= k; i++)
            arr[i]--, num++;
    }
    else
    {
        for(int i = mi + 1; i <= k; i++)
            arr[i]--, num++;
    }
    // Set num
    arr[mi] = num;
    for(ll x : arr)
        cout << x << " ";
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