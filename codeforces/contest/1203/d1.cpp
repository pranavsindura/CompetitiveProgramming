#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    if (s.length() == t.length())
    {
        cout << 0;
    }
    else
    {
        int max = INT_MIN;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                string l, r, join, rem;
                l = s.substr(0, i);
                rem = s.substr(i, j - i + 1);
                r = s.substr(j + 1, s.length() - j + 1);
                // cout << l << " " << rem << " " << r << endl;
                join = l + r;
                int k = 0;
                // cout << join << endl;
                for (int l = 0; l < join.length(); l++)
                {
                    if (join[l] == t[k])
                    {
                        // cout << l << " ";
                        k++;
                    }
                    if (k == t.length())
                        break;
                }
                // cout << endl;
                if (k == t.length())
                {
                    // cout<<l<<" "<<rem<<" "<<r<<endl;
                    if ((int)rem.length() > max)
                        max = (int)rem.length();
                    // cout << max << endl;
                    // cout<<rem.length()<<endl;
                }
            }
        }
        cout << max;
    }

    return 0;
}
