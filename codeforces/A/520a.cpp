#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    string str;
    set<char> s;
    cin >> n >> str;
    for(char x : str)
    {
        s.insert(tolower(x));
    }
    // for(auto x: s)
    //     cout<<x<<" ";
    // cout<<endl;
    if(s.size() == 26)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}