#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n,k;
    cin>>k>>n;
    for(int i=1;i<=10;i++)
    {
        if((k*i)%10 == 0 || (k*i)%10 == n)
        {
            cout<<i;
            break;
        }
    }

    return 0;
}