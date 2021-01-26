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

// ll s[100005];
vector<ll> s(100005, 0);
void init()
{
    s[1] = 1;
    for(int i = 2; i <= 100000; i++)
    {
        s[i] = s[i - 1] + i;
    }
}

int main()
{
    init();
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b;
        cin >> a >> b;
        int ans = 0;
        if(a==b)
            ans=0;
        else
        {
            for(ll i=1;i<=100000;i++)
            {
                ll res = i*(i+1)/2+a+b;
                if(res%2==0 && res/2 >= a && res/2 >= b){
                    ans=i;
                    break;
                }
                // ll c = i;
                // ll x = c-a;
                // ll y = c-b;
                // if(x < 0 || y<0)
                //     continue;
                // if(binary_search(all(s), x+y))
                // {
                //     cout<<c<<" ";
                //     auto it = lower_bound(all(s), x+y);
                //     int ind = it-s.begin();
                //     ans = ind;
                //     break;
                // }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}