#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    string s="";
    char x='z';
    while(x != '}')
    {
        x = getchar();
        s+=x;
    }
    set<char> se;
    for (int i=0;i<s.length();i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            se.insert(s[i]);
    }
    cout << se.size();
    return 0;
}