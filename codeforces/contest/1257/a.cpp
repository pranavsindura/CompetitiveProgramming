#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define FASTIO {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,a,b;
        cin>>n>>x>>a>>b;
        int ans = abs(b-a)+x;
        if(ans>=n)
            ans = n-1;
        cout<<ans<<endl;
    }
    return 0;
}