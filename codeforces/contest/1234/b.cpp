#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x, len = 0;
    cin >> n >> k;
    deque<int> q;
    // map<int, int> m;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        // auto it = find(q.begin(), q.end(), x);
        // auto it = m.find(x);
        // if (it == m.end())
        if (s.count(x) == 0)
        {
            if (len == k)
            {
                auto v = q.back();
                s.erase(v);
                q.pop_back();
                len--;
            }
            q.push_front(x);
            // m[x] = 1;
            s.insert(x);
            len++;
        }
    }
    cout << q.size() << endl;
    for (int j = 0; j < len; j++)
    {
        cout << q[j] << " ";
    }
    return 0;
}