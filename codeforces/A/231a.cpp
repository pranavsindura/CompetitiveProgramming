#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,count=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d = 0;
        cin >> a >> b >> c;
        if (a)
            d++;
        if (b)
            d++;
        if (c)
            d++;
        if(d>=2)
            count++;
    }
    cout<<count;
    return 0;
}