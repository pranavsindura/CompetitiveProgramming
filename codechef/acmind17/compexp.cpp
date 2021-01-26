#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double n, k;
        cin>>n>>k;
        cout << fixed << setprecision(10);
        double ans;
        ans = 2*(((n-1)*(k-1)/(k)) + 1);
        cout<<ans<<endl;
    }
    return 0;
}