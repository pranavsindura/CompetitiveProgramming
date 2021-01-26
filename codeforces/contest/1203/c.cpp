#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll g(ll a, ll b)
{
    if (a == 0)
        return b;
    return g(b % a, a);
}
ll fgcd(ll arr[], ll n)
{
    ll ans = arr[0];
    for (ll i = 1; i < n; i++)
        ans = g(arr[i], ans);

    return ans;
}
int main()
{
    int n,i,j;
    cin>>n;
    ll arr[n],c=0;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll s=fgcd(arr,n);
    for(i=1;i<=sqrt(s);i++)
    {
        if (s%i == 0)
        {
            if (s/i == i)
                c++;

            else
                c+=2;
        }
    }
    cout<<c;
}
