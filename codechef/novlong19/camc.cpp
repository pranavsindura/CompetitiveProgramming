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
        set<pair<int, int>> s;
        vector<int> v(m);
        int x = 0, e;
        for (int i = 0; i < n; i++)
        {
            cin >> e;
            s.insert({e, x});
            x = (x + 1) % m;
        }
        set<int> distinct;
        int mindiff = INT_MAX;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            if (distinct.size() != m)
            {
                distinct.insert(it->second);
                v[it->second] = it->first;
            }
            else
            {
                break;
            }
        }
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            v[it->second] = it->first;
            mindiff = min(mindiff, *max_element(all(v)) - *min_element(all(v)));
        }
        cout << mindiff << endl;
    }
}