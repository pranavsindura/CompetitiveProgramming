#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    string s;
    cin>>s;
    int low=0, upp=0;
    for(char c: s)
    {
        if(c>='a' && c<='z')
            low++;
        else
            upp++;
    }
    if(upp>low)
    {
        for(int i=0;i<s.length();i++)
        {
            s[i] = toupper(s[i]);
        }
    }
    else
    {
        for(int i=0;i<s.length();i++)
        {
            s[i] = tolower(s[i]);
        }
    }
    cout<<s;
    return 0;
}