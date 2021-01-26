#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
    int n,m,a,b;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<bool> rem(n+1, false);
    for(int i=0;i<m;i++)
    {
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    
    int ans = 0;
    bool f = true;
    while(f)
    {
    f = false;  
    vector<int> remnow;
    for(int i=1;i<=n;i++)
    {
      if(rem[i])
        continue;
      vector<int> c;
      for(int u: adj[i])
      {
        if(!rem[u])
          c.push_back(u);
      }
      if(c.size() == 1)
      {
        //cout<<"removed: "<<i<<endl;
        //rem[i] = true;
        remnow.push_back(i);
        f = true;
      }
    }
    for(int x: remnow)
      rem[x] = true;
    if(f)
      ans++;
    
    }
    cout<<ans;
    return 0;
}