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
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

void cp()
{
    int n, k;
    cin >> k >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    sort(all(arr));
    int mn = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        int d = (arr[j]-arr[i]+k)%k;
        mn = min(k - d, mn);
        j = (i + n - 1) % n;
        d = (arr[i]-arr[j]+k)%k;
        mn = min(k - d, mn);
    }
    cout<<mn;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin>>t;
    while(t--)
    {
        cp();
    }
    return 0;
}