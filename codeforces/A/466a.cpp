#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if((double)b/(double)m >= a)
    {
        cout<<n*a;
    }
    else
    {
        int trips = n/m;
        trips *= b;
        int left = n%m;
        if(left*a > b)
            cout << trips+b;
        else
            cout << trips+left*a; 
    }
    return 0;
}