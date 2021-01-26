#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,k,i,j;
        cin>>a>>b>>c>>d>>k;
        if(a%c==0)
        {
            i=a/c;
        }
        else
        {
            i=a/c;
            i++;
        }
        if(b%d==0)
        {
            j=b/d;
        }
        else
        {
            j=b/d;
            j++;
        }
        if(i+j<=k)
        {
            cout<<i<<" "<<j<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }   
    }
}