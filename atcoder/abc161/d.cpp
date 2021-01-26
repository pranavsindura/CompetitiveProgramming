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

set<ll> vis;
void bfs()
{
    queue<ll> q;
    for(int i = 1; i < 10; i++)
        vis.insert(i), q.push(i);
    while(!q.empty())
    {
        ll x = q.front();
        q.pop();
        int last = x%10;
        vector<int> temp;
        temp.pb(last-1);
        temp.pb(last);
        temp.pb(last+1);
        // cout<<last<<": ";
        for(int i=0;i<3;i++)
        {
            if(temp[i] >=0 && temp[i] <= 9)
            {
                // cout<<c<<" ";
                x = x*10+temp[i];
                if(vis.lower_bound(x) == vis.end() && x <= 3234566667 )
                {
                    q.push(x);
                    vis.insert(x);
                }
                x = x/10;
            }
        }
        // cout<<endl;
    }

}
void cp()
{
    int k,c=0;
    cin >> k;
    bfs();
    ll ans;
    for(auto it=vis.begin(); it!=vis.end();it++)
    {
        c++;
        ans = *it;
        // cout<<*it<<" ";
        if(c==k){
            break;
        }

    }
    // cout<<endl;
    cout<<ans;
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