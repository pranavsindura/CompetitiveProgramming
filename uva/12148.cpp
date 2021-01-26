#include <bits/stdc++.h>
using namespace std;
int daysinmonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Date
{
    int d, m, y, cons;
    Date()
    {
        d=0;
        m=0;
        y=0;
        cons=0;
    }
    Date(Date &x)
    {
        d = x.d;
        m = x.m;
        y = x.y;
        cons = x.cons;
    }
};
#define Date struct Date
bool leap(int y)
{
    if (y % 400 == 0)
        return true;
    if (y % 100 == 0)
        return false;
    if (y % 4 == 0)
        return true;
    return false;
}
bool check(Date &prev, Date curr)
{
    if (leap(prev.y))
        daysinmonth[2] = 29;
    else
        daysinmonth[2] = 28;
    if (prev.d == daysinmonth[prev.m])
    {
        prev.d = 1;
        if (prev.m == 12)
        {
            prev.m = 1;
            prev.y++;
        }
        else
            prev.m++;
    }
    else
    {
        prev.d++;
    }
    if (prev.d == curr.d && prev.m == curr.m && prev.y == curr.y)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin >> n;
    while (n)
    {
        Date prev, curr;
        int count = 0, total = 0;
        cin >> prev.d >> prev.m >> prev.y >> prev.cons;
        for (int i = 1; i < n; i++)
        {
            cin >> curr.d >> curr.m >> curr.y >> curr.cons;
            if (check(prev, curr))
            {
                total += curr.cons - prev.cons;
                count++;
            }
            prev = curr;
        }
        cout << count << " " << total << endl;
        cin >> n;
    }
    return 0;
}