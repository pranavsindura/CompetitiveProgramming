#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    map<char,int> m;
    cin>>n;
    string s;
    cin>>s;
    for(int i=1;i<n;i++)
    {
        if(s[i] == s[i-1])
        {
            m[s[i]]++;
        }
    }
    cout<<m['R']+m['G']+m['B'];
    return 0;
}