#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        bitset<10> res(s), temp;
        for(int i=1;i<n;i++)
        {
            cin>>s;
            temp = bitset<10>(s);
            res = res^temp;
        }
        cout<<res.count()<<endl;
    }
    return 0;
}