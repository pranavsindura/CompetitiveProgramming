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
vector<ll> sum(100005, 0);
void init()
{
    for(int i=1;i<sz(sum);i++)
    {
        sum[i] = sum[i-1]+i;
    }
}
int main()
{
    FASTIO;
    init();
    int t;
    cin>>t;
    while(t--)
    {
    	ll n,k;
        cin>>n>>k;
        auto it = lower_bound(all(sum), k);
        int ind = it-sum.begin();
        int a = ind;
        int b = k-sum[ind-1]-1;
        string s;
        for(int i=0;i<n;i++)
        {
            if(i==a || i==b)
                s.pb('b');
            else
                s.pb('a');
        }
        reverse(all(s));
        cout<<s<<endl;
    }
    return 0;
}