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

ll sum(vector<ll> &arr, int l, int r)
{
    ll a = arr[r];
    if(l)
        a -= arr[l-1];
    return a;
}

int main()
{
    FASTIO;
    int n;
    cin>>n;
    vector<int> arr(n), s(n);
    vector<ll> pre(n), spre(n);
    for(int i=0;i<n;i++)
        cin>>arr[i], s[i]=arr[i];
    sort(all(s));
    pre[0]=arr[0];
    spre[0]=s[0];
    for(int i=1;i<n;i++)
    {
        pre[i] = pre[i-1]+arr[i];
        spre[i] = spre[i-1]+s[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int type,l,r;
        cin>>type>>l>>r;
        l--, r--;
        if(type==1)
        {
            cout<<sum(pre, l ,r)<<endl;
        }
        else
        {
            cout<<sum(spre, l ,r)<<endl;
        }
    }
    return 0;
}