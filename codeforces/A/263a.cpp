#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    // int mat[6][6] = {0};
    int r, c, x;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> x;
            if (x)
            {
                r = i;
                c = j;
            }
        }
    }
    x=abs(3-r)+abs(3-c);
    cout<<x;
    return 0;
}