#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back({x,i+1});
    }
    sort(v.begin(),v.end(),[](pair<int,int> a, pair<int,int> b){return a.first > b.first;});
    long long int c=0, total=0;
    for(int i=0;i<n;i++)
    {
        total += v[i].first*c + 1;
        c++;
    }
    cout<<total<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i].second<<" ";
    return 0;
}
