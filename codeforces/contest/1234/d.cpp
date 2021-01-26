#include <bits/stdc++.h>
using namespace std;
int dp[26][1000005];
string s;
vector<set<int>> alpha(26);
void print()
{
    cout << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << char(i + 'a') << ": ";
        for (int j = 0; j < s.length(); j++)
        {
            cout << dp[i][j];
        }
        cout << endl;
    }
}
int main()
{
    cin >> s;

    // for (int i = 0; i < 26; i++)
    // {

    //     for (int j = 0; j < s.length(); j++)
    //     {
    //         dp[i][j] = (int(s[j]) == (97 + i));
    //     }
    // }
    for (int i = 0; i < s.length(); i++)
    {
        alpha[s[i] - 'a'].insert(i + 1);
    }
    int q, t;
    cin >> q;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            int pos;
            char c;
            cin >> pos >> c;
            alpha[s[pos - 1] - 'a'].erase(pos);
            alpha[c - 'a'].insert(pos);
            // dp[s[pos - 1] - 'a'][pos - 1] = 0;
            // dp[c - 'a'][pos - 1] = 1;
            s[pos - 1] = c;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int c = 0;
            // print();
            for (int i = 0; i < 26; i++)
            {
                // if (binary_search(dp[i] + l - 1, dp[i] + r, 1))
                // if (binarySearch(dp[i], l - 1, r - 1, 1))
                auto it = alpha[i].lower_bound(l);
                if(it != alpha[i].end() && *it <= r)
                {
                    c++;
                    // cout << "found " << char(97 + i) << endl;
                }

                // for (int j = l - 1; j < r; j++)
                // {
                //     if (dp[i][j])
                //     {
                //         c++;
                //         break;
                //     }
                // }
            }
            cout << c << endl;
            // set<char> se;
            // for (int i = l - 1; i < r; i++)
            // {
            //     se.insert(s[i]);
            // }
            // cout << se.size() << endl;
        }
    }
    return 0;
}