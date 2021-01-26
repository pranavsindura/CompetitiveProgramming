#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
bool check(char x)
{
    if(x == '#')
        return true;
    else
        return false;
}
int main()
{
    FASTIO;
    int n, x;
    cin>>n;
    vector<int> f(10001, 0);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        f[x]++;
    }
    int maxf = *max_element(all(f));
    if(maxf > (n+1)/2)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}