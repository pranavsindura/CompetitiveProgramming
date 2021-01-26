#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

//for a subarray of size x
//x! is permutations of the numbers inside it
//(n-x+1)! is the permutation of the whole array with subarray as one unit
//this can be done for every subarray of size x, number of such subarrays are (n-x+1)

//for a subarray of size i
// i! * (n-i+1)! * (n-i+1)
int main()
{
    FASTIO;
    int n,m;
    cin>>n>>m;
    ll fact[n+1];
    fact[0]=1;
    for(int i=1;i<=n;i++)
    	fact[i] = (fact[i-1]%m * i%m)%m;
    ll ans = 0;
    for(int i=1;i<=n;i++)
    	ans = (ans%m + fact[i]%m * fact[n-i+1]%m * (n-i+1)%m)%m;
    cout<<ans;
    return 0;
}