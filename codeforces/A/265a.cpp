#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    string s, t;
    cin>>s>>t;
    s = ' '+s;
    int k=1;
    for(int i=0;i<t.length();i++)
    {
        if(s[k] == t[i])
            k++;
    }
    cout<<k;
    return 0;
}