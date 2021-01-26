#include <bits/stdc++.h>
#define ll long long int
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;
bool check(char x)
{
    if(x == 'C' || x == 'M' || x == 'Y' || x == 'K')
        return true;
    else
        return false;
}
int main()
{
    FASTIO;
    int n, m;
    cin >> n >> m;
    bool color = false;
    char x;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> x;
            if(check(x))
                color = true;
        }
    }
    if(color)
        cout << "#Color";
    else
        cout << "#Black&White";
    return 0;
}