#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define test int t;cin>>t;while(t--)
using namespace std;
struct point
{
    int x, y;
};
#define point struct point
int main()
{
    FASTIO;
    test
    {
        int n;
        cin>>n;
        n = 180 - n;
        if(360%n)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}