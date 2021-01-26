#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    string s="";
    for (int i=0, c=0; i<n; i++, c = (c+1)%k)
    {
        s += char(97+c);
    }
    cout<<s;
}