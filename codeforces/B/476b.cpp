#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//Compiler version g++ 6.3.0
int ans=0, total=0;
int check(char x)
{
  if(x=='+')
  return 1;
  else
  return -1;
}
void rec(int pos, int n, string a, string b, int curr,int final)
{
  if(pos == n)
  {
    if(curr == final)
      ans++;
    total++;
    return;
  }
  else{
    if(b[pos] == '?')
    {
      rec(pos+1, n, a, b, curr+1, final);
      rec(pos+1, n, a, b, curr-1, final);
    }
    else
    {
      rec(pos+1, n, a, b, curr+check(b[pos]), final);
    }
  }
  
}
int main()
{
    string a,b;
    cin>>a>>b;
    int n = a.length();
    int final = 0;
    for(char x: a)
    {
      final += check(x);
    }
    rec(0, n, a, b, 0, final);
    double x = ans*1.0, y = total*1.0;
    double z = x/y;
    cout<<fixed<<setprecision(10)<<z;
}