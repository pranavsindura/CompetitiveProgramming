#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c = 0, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 1)
            c++;
    }
    if (c)

        cout << "HARD";
    else
        cout << "EASY";
    // cout << n;
    return 0;
}