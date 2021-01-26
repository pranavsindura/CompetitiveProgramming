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
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    map<ll, int> mp;
    ll sum = 0, ans=0;
    mp[0] = -1;
    int mx = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += 1LL * arr[i];
        if(mp.find(sum) != mp.end())
        {
        	if(sum == 0 && mp[0] == -1)
        	{
        		mx = max(mx, 1);
        	}
        	else
        		mx = max(mx, mp[sum]+1);
        }
        mp[sum] = i;
        ans += i - mx;
    }
    cout << ans;
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