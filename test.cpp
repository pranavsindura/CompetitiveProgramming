#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for(int &x : arr)
            cin >> x;

        set<int> take;
        int mask = 0;
        for(int b = 20; b >= 0; b--)
        {
            sort(arr.rbegin(), arr.rend());
            if()
        }
        // sanity check
        int all = 0;
        for(int x : arr) all |= x;
        assert(have == all);
        cout << need << endl;
    }
}