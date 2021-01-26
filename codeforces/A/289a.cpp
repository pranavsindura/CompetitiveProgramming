#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n, k, a, b, range = 0,ans;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        range += b - a + 1;
    }
    if(range%k == 0)
    	ans = 0;
    else
    {
    	ans = k - range%k;
    }
    cout<<ans;
    return 0;
}