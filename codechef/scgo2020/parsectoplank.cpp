#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int solve(int n,int k)
{
    if(n==1)
        return n;
    else
        return (solve(n-1,k)+k)%n +1;
}
int main()
{
    FASTIO;
    int n;
    cin>>n;
    cout<<solve(2020,n);
    return 0;
}