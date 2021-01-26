#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, ox1, oy1, ox2, oy2, ox3, oy3, ox4, oy4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    if (x3 <= x1 && x4 > x1 && y3 <= y1 && y4 >= y2)
    {
        if (x4 >= x2)
        {
            cout << "NO";
            return 0;
        }
        x1 = x4;
    }
    else if (x4 >= x2 && x3 < x2 && y3 <= y1 && y4 >= y2)
        x2 = x3;
    else if (y3 <= y1 && y4 > y1 && x3 <= x1 && x4 >= x2)
        y1 = y4;
    else if (y4 >= y2 && y3 < y2 && x3 <= x1 && x4 >= x2)
        y2 = y3;
    if (x5 <= x1 && x6 >= x2 && y5 <= y1 && y6 >= y2)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES";
    return 0;
}
