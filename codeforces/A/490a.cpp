#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    int n,a,b,c,x;
    cin>>n;
    vector<int> pro, math, pe;
    for (int i = 1; i <= n;i++)
    {
        cin>>x;
        if(x == 1)
            pro.push_back(i);
        else if(x == 2)
            math.push_back(i);
        else if(x == 3)
            pe.push_back(i);
    }
    int m = min((int)pe.size(), (int)math.size());
    m = min(m, (int)pro.size());
    cout<<m<<endl;
    for(int i = 0; i < m;i++)
        cout<<pro[i]<<" "<<math[i]<<" "<<pe[i]<<endl;
    return 0;
}