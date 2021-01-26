#include <bits/stdc++.h>
#define ll long long int
#define fast                              \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;
//0-chef, 1-ramsay
pair<int, int> rec(vector<deque<int>> &coin, int n, int player, int coinleft, int chefsum, int ramsum)
{
    if (coinleft == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (coin[i].size())
            {
                if (player == 0)
                    chefsum += coin[i].front();
                else
                    ramsum += coin[i].front();
                coin[i].pop_front();
                // cout << chefsum << " " << ramsum << " " << coinleft << endl;
                return make_pair(chefsum, ramsum);
            }
        }
    }
    pair<int, int> ans;
    if (player == 0)
    {
        int maxc = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (coin[i].size())
            {
                int x = coin[i].front();
                coin[i].pop_front();
                pair<int, int> val = rec(coin, n, 1, coinleft - 1, chefsum, ramsum);
                if (maxc < (val.first + x + chefsum))
                {
                    maxc = val.first + x + chefsum;
                    ans = make_pair(val.first + x + chefsum, val.second + ramsum);
                }
                coin[i].push_front(x);
            }
        }
        cout << "chef: " << ans.first << endl;
        return ans;
    }
    else
    {
        int maxr = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (coin[i].size())
            {
                int x = coin[i].back();
                coin[i].pop_back();
                pair<int, int> val = rec(coin, n, 0, coinleft - 1, chefsum, ramsum);
                if (maxr < (val.second + x + ramsum))
                {
                    maxr = val.second + x + ramsum;
                    ans = make_pair(val.first + chefsum, val.second + x + ramsum);
                }
                coin[i].push_back(x);
            }
        }
        cout << "ramsey: " << ans.second << endl;
        return ans;
    }
}

int main()
{
    // fast;
    int t;
    // cin >> t;
    scanf("%d", &t);
    while (t--)
    {
        int n, c = 0;
        // cin >> n;
        scanf("%d", &n);
        vector<deque<int>> coin(n);
        for (int i = 0; i < n; i++)
        {
            int clen, x;
            // cin >> clen;
            scanf("%d", &clen);
            c += clen;
            for (int j = 0; j < clen; j++)
            {
                // cin >> x;
                scanf("%d", &x);
                coin[i].push_back(x);
            }
        }
        pair<int, int> ans = rec(coin, n, 0, c, 0, 0);
        // cout << ans.first << endl;
        printf("%d\n", ans.first);
    }
    return 0;
}