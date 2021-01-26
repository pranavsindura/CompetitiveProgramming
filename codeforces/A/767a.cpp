#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    vector<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push_back(x);
    }
    bool mark[n + 1];
    set<int, greater<int>> s;
    memset(mark, false, sizeof(mark));
    int wait = n, i = 0;
    for (i = 0; i < n; i++)
    {
        mark[q[i]] = true;
        s.insert(q[i]);
        if (q[i] == wait)
        {
            while (mark[wait])
            {
                cout<<wait<<" ";
                wait--;
            }
            // for(auto e: s)
            //     cout<<e<<" ";
            // s.clear();
        }
        cout << endl;
        // while(mark[wait])
        //     wait--;
    }
    return 0;
}