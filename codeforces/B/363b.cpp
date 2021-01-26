#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vpii vector<pii>
#define vll vector<ll>
const double PI = acos(-1.0);
using namespace std;
int sum(vector<int> &arr, int l, int r)
{
    int a = arr[r];
    if(l)
        a -= arr[l - 1];
    return a;
}
int main()
{
    FASTIO;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i < n; i++)
        arr[i] += arr[i - 1];
    int ans, minh=INT_MAX;
    k--;
    for(int i = 0; i < n - k; i++)
    {
    	int curr = sum(arr, i, i+k);
    	if(curr<minh)
    	{
    		minh = curr;
    		ans = i+1;
    	}
    }
    cout<<ans;
    return 0;
}