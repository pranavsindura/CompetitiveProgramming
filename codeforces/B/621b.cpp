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
const double PI = acos(-1.0);
using namespace std;

bool arr[1005][1005];
int n,a,b;
bool valid(int i, int j)
{
  return (i>0&&i<=1000&&j>0&&j<=1000);
}
int main()
{
    FASTIO;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cin>>a>>b;
      arr[a][b]=true;
    }
    ll ans =0;
    for(int a=1;a<=1000;a++)
    {
      int i=a,j=1;
      ll c=0;
      while(valid(i,j))
      {
        c+=arr[i][j];
        i--,j++;
      }
      ans += c*(c-1)/2;
    }
    for(int a=2;a<=1000;a++)
    {
      int i=1000,j=a;
      ll c=0;
      while(valid(i,j))
      {
        c+=arr[i][j];
        i--,j++;
      }
      ans += c*(c-1)/2;
    }
    for(int a=1000;a>0;a--)
    {
      int i=1,j=a;
      ll c=0;
      while(valid(i,j))
      {
        c+=arr[i][j];
        i++,j++;
      }
      ans += c*(c-1)/2;
    }
    for(int a=2;a<=1000;a++)
    {
      int i=a,j=1;
      ll c=0;
      while(valid(i,j))
      {
        c+=arr[i][j];
        i++,j++;
      }
      ans += c*(c-1)/2;
    }
    cout<<ans;
    return 0;
}
    