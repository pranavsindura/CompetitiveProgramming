#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, x, ind;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr.push_back(x);
            if (x == 1)
            {
                ind = i;
            }
        }
        bool c = true, cc = true;
        for (int i = 0, j = ind; i < n-1; i++, j = (j + 1) % n)
        {
            if (arr[(j + 1) % n] < arr[j])
            {
                c = false;
                break;
            }
        }
        for (int i = 0, j = ind; i < n-1; i++, j = (n + j - 1) % n)
        {
            if (arr[(n + j - 1) % n] < arr[j])
            {
                cc = false;
                break;
            }
        }
        if (!c && !cc)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}
