#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        v.push_back(x);
    }

    int mine = *min_element(v.begin(), v.end());
    int maxe = *max_element(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if(v[i] > mine && v[i] < maxe)
            ans++;
    }
    cout<<ans;
    return 0;
}