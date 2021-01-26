#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    int c = 0;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] > s2[i])
        {
            c = 1;
            break;
        }
        else if (s1[i] < s2[i])
        {
            c = -1;
            break;
        }
    }
    cout<<c;
}