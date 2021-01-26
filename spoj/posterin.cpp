#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
    int n, x, y;
    cin>>n;
    stack<int> s;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
      cin>>x>>y;
      if(s.empty()){
         ans++;
         s.push(y);
      }
      else{
        while(s.top() > y)
        {
          s.pop();
          if(s.empty())
            break;
        }
        if(s.empty())
        {
          ans++;
          s.push(y);
        }
        else if(s.top() < y)
          ans++, s.push(y);
      }
    }
    cout<<ans;
}