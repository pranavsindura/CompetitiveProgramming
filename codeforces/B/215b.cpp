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

int main()
{
    int n,m,k,x,a,b;
    vector<int> r1, p1, p2;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cin>>x;
      r1.push_back(x);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
      cin>>x;
      p1.push_back(x);
    }
    cin>>k;
    for(int i=0;i<k;i++)
    {
      cin>>x;
      p2.push_back(x);
    }
    cin>>a>>b;
    int maxr1 = *max_element(all(r1));
    maxr1 *= maxr1;
    // cout<<maxr1<<endl;
    double ma = DBL_MIN;
    for(int i=0;i<k;i++)
    {
      for(int j=0;j<m;j++)
      {
        double curr = (b*p1[j]*1.0)/((b*p1[j]*1.0) + (a*p2[i]*1.0));
        ma = max(ma, curr);
        // if(curr > ma)
        // {
        //   minr = curr;
        //   cout<<p2[i]<<" "<<p1[j]<<endl;
        //   cout<<minr<<endl;
        // }
      }
    }
    double maxr = (maxr1*1.0);
    maxr *= ma;
    maxr = sqrt(maxr);
    cout<<fixed<<setprecision(15)<<maxr;
}