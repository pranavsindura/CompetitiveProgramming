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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(2 * n);
        for(int &x : arr)cin >> x;
        sort(all(arr));
        int mx = INT_MAX;
        cout<<abs(arr[n]-arr[n-1])<<endl;
        // for(int diff = 1; diff <= n; diff++)
        // {
        //     for(int i = 0; i < 2 * n - diff; i++)
        //     {
        //         int s = i, g = 2 * n - 2 - i;
        //         if(s % 2 || g % 2)
        //             continue;
        //         int as = s / 2, ag = g / 2;
        //         if(as == ag)
        //         {
        //             mx = min(mx, abs(arr[i] - arr[i + 1]));
        //         }
        //     }
        // }

        // cout << mx << endl;
    }
    return 0;
}