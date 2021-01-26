#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, x;
        cin >> n;
        map<int, int> stick;
        vector<int> v;
        for (int i = 0; i < 4 * n; i++)
        {
            cin >> x;
            stick[x]++;
            v.push_back(x);
        }
        bool flag = true;
        for (auto it = stick.begin(); it != stick.end(); it++)
        {
            if (it->second % 2 != 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            sort(v.begin(), v.end());
            int size = v.size();
            for(int i=1; i<(size/2); i++)
            {
                int area = v[i] * v[size-i-1];
                int prev = v[i-1] * v[size-(i-1)-1];
                if(area != prev)
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
