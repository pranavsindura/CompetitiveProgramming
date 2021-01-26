#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int cal[5];
    string s;
    ll sum=0;
    for(int i=1;i<=4;i++)
        cin>>cal[i];
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        sum += cal[s[i]-'0'];
    }
    cout<<sum;
    return 0;
}