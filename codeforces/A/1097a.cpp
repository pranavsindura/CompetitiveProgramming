#include <bits/stdc++.h>
using namespace std;

int main()
{
    string arr[6];
    int f = 0;
    for (int i = 0; i < 6; i++)
        cin >> arr[i];
    for (int i = 1; i < 6; i++)
    {
        if (arr[i][0] == arr[0][0] || arr[i][1] == arr[0][1])
        {
            f = 1;
            break;
        }
    }
    if (f)
        cout << "YES";
    else
    {
        cout << "NO";
    }
}