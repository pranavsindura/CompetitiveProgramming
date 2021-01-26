#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k;
        vector<int> less, greater;
        ll sum = 0, remsum = 0, totalsum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x <= k)
            {
                less.push_back(x);
                sum += x;
            }
            else
            {
                greater.push_back(x - k);
                remsum += (x - k);
            }
            totalsum += x;
        }
        sort(greater.begin(), greater.end());
        int size = greater.size();
        if (size > 1)
        {
            sum += size * k;
            ll rem = remsum - greater[size - 1] - greater[size - 2];
            if (rem < greater[size - 2])
            {
                sum += greater[size - 1] - (greater[size - 2] - rem);
                cout << sum << endl;
            }
            else
            {
                if (rem % 2 != greater[size - 2] % 2)
                {
                    sum += greater[size - 1] - 1;
                }
                else
                {
                    sum += greater[size - 1];
                }
                cout << sum << endl;
            }
        }
        else
        {
            cout << totalsum << endl;
        }
    }
    return 0;
}
