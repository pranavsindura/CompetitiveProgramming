#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    int children[n];
    for (int i = 0; i < n; i++)
        cin >> children[i];
    vector<pair<int, int>> mango;
    int mangosum[m+1];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        mango.push_back({x, y});
    }
    sort(mango.begin(), mango.end(), [](pair<int, int> a, pair<int, int> b) { return (a.first < b.first); });

    // for (auto it = mango.begin(); it!= mango.end(); it++)
    // {
    //     cout << it-mango.begin()<<" "<< it->first << " " << it->second << endl;
    // }
    // mangosum[0] = 0;
    mangosum[0] = mango[0].second;
    for (int i = 1; i < m; i++)
    {
        mangosum[i] = mangosum[i - 1] + mango[i].second;
    }
    // for (auto it = mango.begin(); it != mango.end(); it++)
    // {
    //     cout<<it->first<<" "<<it->second<<endl;
    // }

    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(mango.begin(), mango.end(), make_pair(children[i], INT_MAX));
        int ind = (it - mango.begin());
        if(ind == 0)
            cout<<"0 ";
        else if(it == mango.end())
            cout<<mangosum[m-1]<<" ";
        else
        // cout<<children[i]<<"->"<<ind<<endl;
        // cout<<ind<<" "<<it->first<<" "<<it->second<<endl;
        cout << mangosum[ind-1] << " "<<endl;
    }
    return 0;
}