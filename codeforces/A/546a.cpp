#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,n,w;
    cin>>k>>n>>w;
    int total = (w*(w+1))/2 * k;
    total -= n;
    if(total<0) total = 0;
    cout<<total;
}