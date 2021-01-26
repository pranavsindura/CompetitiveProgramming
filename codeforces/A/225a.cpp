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
    int n, top, a, b;
    bool f = true;
    cin >> n >> top;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(top == a || top == b || top == 7 - a || top == 7 - b)
            f = false;
        top = 7 - top;
    }
    if(f)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}