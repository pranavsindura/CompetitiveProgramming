#include <bits/stdc++.h>
#define ll long long int
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;
int main()
{
    FASTIO;
    int n, x;
    cin >> n >> x;
    if(x == 10)
    {
        if(n > 1)
        {
            for(int i = 0; i < n - 1; i++)
                cout << 9;
            cout << 0;
        }
        else
                cout<<-1;
    }
    else
    {
        for(int i = 0; i < n; i++)
            cout << x;
    }

}