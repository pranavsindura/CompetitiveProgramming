#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.rbegin(), v.rend());
    int lst = INT_MAX, c = 0;
    for (int i = 0; i < n; i++)
    {
        bool poss = false;
        int cur = 0;
        if ((v[i] + 1) > 0 && (v[i] + 1) < lst)
        {
            poss = true;
            cur = v[i] + 1;
        }
        if (!poss)
        {
            if (v[i] > 0 && v[i] < lst)
            {
                poss = true;
                cur = v[i];
            }
        }
        if (!poss)
        {
            if ((v[i] - 1) > 0 && (v[i] - 1) < lst)
            {
                poss = true;
                cur = v[i] - 1;
            }
        }

        if (poss)
        {
            c++;
            lst = cur;
        }
    }
    cout << c;
    return 0;
}
