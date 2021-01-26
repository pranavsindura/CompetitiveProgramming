#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    set<char> se;
    for(int i=0;i<s.length();i++)
    {
        se.insert(s[i]);
    }
    if(se.size()&1)
        cout<<"IGNORE HIM!";
    else
        cout<<"CHAT WITH HER!";
}