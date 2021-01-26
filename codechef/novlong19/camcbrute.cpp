#include <bits/stdc++.h>
#define ll long long int
#define ii pair<int, int>
#define all(x) x.begin(), x.end()
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> arr(n);
        vector<set<int>> b(m);
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = x;
            b[x].insert(i);
            x = (x + 1) % m;
        }
        sort(all(arr), [](ii a, ii b) { return a.first < b.first; });
        set<int> picked;
        vector<ii> dq;
        int mind = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            picked.clear();
            dq.clear();
            for (int j = i; j < n; j++)
            {
                if (!picked.count(arr[j].second))
                {
                    dq.push_back(arr[j]);
                    picked.insert(arr[j].second);
                }
                if (picked.size() == m)
                {
                    int currdiff = dq[m - 1].first - dq[0].first;
                    if (currdiff < mind)
                        mind = currdiff;
                    break;
                }
            }
        }
        cout << mind << endl;
    }
}