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
    int n;
    cin >> n;
    vector<int> arr;
    vector<int> v;
    map<int, int> semi, ind;
    vector<vector<bool>> ans(2, vector<bool>(n, false));
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a > b)
        {
            arr.pb(b);
            arr.pb(a);
        }
        else
        {
            arr.pb(a);
            arr.pb(b);
        }
        v.pb(a);
        v.pb(b);
        semi[a] = 0, semi[b] = 1, ind[a] = i, ind[b] = i;
    }
    sort(all(v));
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        ans[ semi[ v[i] ] ][ ind[ v[i] ] ] = true;
    }

    for(int i = 0; i < n/2 ; i++)
    {
        ans[ 0 ][ i ] = true;
        ans[ 1 ][ i ] = true;
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}