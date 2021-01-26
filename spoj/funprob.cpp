#include<bits/stdc++.h>
using namespace std;
// BERTRAND'S BALLOT THEOREM (TIES ALLOWED)
int main()
{
    int n, m;
    cin >> n >> m;
    while(n || m)
    {
        double a = n, b = m;
        if(n > m)
            cout << "0.000000\n";
        else
            cout << fixed << setprecision(6) << (b + 1 - a) / (b + 1) << endl;
        cin >> n >> m;
    }
    return 0;
}