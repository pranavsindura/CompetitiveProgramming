#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n,c=0;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i].first>>v[i].second;
    for(int i = 0; i < n;i++)
    {
        for(int j=0; j < n; j++)
        {
            if(v[i].first == v[j].second)
                c++;
        }
    }
    cout<<c;
    return 0;
}