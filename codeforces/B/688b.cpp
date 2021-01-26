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
bool valid(int i, int j, int n, int m)
{
    if(i>=0 && i<n && j >=0 && j < m)
        return true;
    else
        return false;
}
int main()
{
    FASTIO;
    string dig;
    cin>>dig;
    string p = dig;
    reverse(all(dig));
    p += dig;
    cout<<p;
    return 0;
}