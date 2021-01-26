#include <bits/stdc++.h>
#define ll long long int
#define watch(x)                         \
    {                                    \
        cout << #x << ": " << x << endl; \
    }
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        // if (k <= n)
        // {
        //     for (int i = 0; i < k; i++)
        //     {
        //         arr[i % n] ^= arr[n - (i % n) - 1];
        //     }
        // }
        // else
        // {
            if (n & 1)
            {
                if (k >= (n * 3))
                    arr[n / 2] = 0;
                ll mod = k % (n * 3);
                for (int i = 0; i < mod; i++)
                {
                    arr[i % n] ^= arr[n - (i % n) - 1];
                }
            }
            else
            {
                ll mod = k % (n * 3);
                for (int i = 0; i < mod; i++)
                {
                    arr[i % n] ^= arr[n - (i % n) - 1];
                }
            }
            // }
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return 0;
    }