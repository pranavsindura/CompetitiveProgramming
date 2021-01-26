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
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    int suff[n + 2];
    suff[0] = -1;
    suff[n + 1] = -1;
    for(int i = n; i >= 1; i--)
        suff[i] = suff[i + 1] & (~arr[i]);
    int ind = 0;
    int mx = INT_MIN;
    int pre = -1;
    for(int i = 1; i <= n; i++)
    {
        int val = arr[i] & pre & suff[i + 1];
        if(val > mx)
            mx = val, ind = i;
        pre = pre & (~arr[i]);
    }
    cout << arr[ind] << " ";
    for(int i = 1; i <= n; i++)
    {
        if(i != ind)
            cout << arr[i] << " ";
    }
    return 0;
}