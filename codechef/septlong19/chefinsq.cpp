#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        vector<int> arr;
        cin >> n >> k;
        // cout<<n;
        // map<int, int> m;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            // cout<<i<<": ";
            cin >> x;
            // cout<<x;
            arr.pb(x);
            // m[x]++;
            // cout << "input " << i << endl;
        }
        // cout << "input taken";
        sort(arr.begin(), arr.end());
        // cout << "sorted";
        // vector<int>::iterator ip = unique(arr.begin(), arr.end());
        // arr.resize(distance(arr.begin(), ip));
        // cout << "resized";
        int sum = 1;
        vector<int>::iterator it = arr.begin();
        for (int i = 0; i < k; i++)
        {
            int c= 0;
            for(int j=k;j<n;j++)
            {
                if(arr[j] == arr[i])
                    c++;
            }
            if(c)
                sum++;
        }
        cout << sum << endl;
    }
    return 0;
}