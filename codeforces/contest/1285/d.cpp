#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

ll rec(vector<int> &a, int bit)
{
    if(a.size() == 0 || bit<0)
        return 0;
    vector<int> l, r;
    for(int i=0;i<sz(a);i++)
    {
        // that bracket is important that encloses x&1
        if(((a[i] >> bit)&1) == 0)
            l.push_back(a[i]);
        else
            r.push_back(a[i]);
    }
    if(r.size()==0)
        return rec(l, bit-1);
    if(l.size()==0)
        return rec(r, bit-1);
    else
        return min(rec(l, bit-1), rec(r, bit-1)) + (1LL<<bit);
}

int main()
{
    FASTIO;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll ans = rec(arr, 30);
    cout<<ans;
    return 0;
}