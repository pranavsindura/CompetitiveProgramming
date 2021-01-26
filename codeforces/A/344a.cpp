#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n, c=1;
    cin>>n;
    string prev="", curr="";
    cin>>prev;
    for(int i=1;i<n;i++)
    {
        cin>>curr;
        if(curr != prev)
            c++;
        prev = curr;
    }
    cout<<c;
    return 0;
}