#include <bits/stdc++.h>
#define ll long long int
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;
vector<int> ans;
bool rec(int place, int last, int sum, int prevdigit)
{
    if (place > last)
    {
        if (int(sqrt(sum)) * int(sqrt(sum)) == sum)
        {
            return true;
        }
        else
            return false;
    }
    else
    {
        for (int i = prevdigit; i < 10; i++)
        {
            if (rec(place + 1, last, sum + i * i, i))
            {
                ans.push_back(i);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ans.clear();
        bool a = rec(0, n - 1, 0, 1);
        if (a)
        {
            for (int i = ans.size() - 1; i >= 0; i--)
                cout << ans[i];
            cout<<endl;
        }
        else
            cout << "-1\n";
    }
}