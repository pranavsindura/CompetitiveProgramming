#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sig;
        cin >> n >> sig;
        double arr[n];
        if(sig!=0 && n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if (sig == 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "1 ";
            }
            cout << endl;
        }
        else if (n % 2 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << sig <<" ";
                sig *= -1;
            }
            cout << endl;
        }
        else
        {
            double num = double(sig)*sqrt(double(n)/double(n-1));
            for (int i = 0; i < n-1; i++)
            {
                cout << num <<" ";
                num *= -1;
            }
            cout<<"0"<<endl;
        }
    }
    return 0;
}