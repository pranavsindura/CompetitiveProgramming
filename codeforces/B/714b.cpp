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
    int n, x;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++)
    {
      cin>>x;
      s.insert(x);
    }

    if(s.size() <= 2)
    {
      cout<<"YES";
    }
    else if(s.size() == 3)
    {
      vector<int> arr;
      for(int a: s)
        arr.push_back(a);
      if(arr[0]+arr[2] == 2*arr[1])
        cout<<"YES";
      else
        cout<<"NO";
    }
    else
    {
      cout<<"NO";
    }
    return 0;
}