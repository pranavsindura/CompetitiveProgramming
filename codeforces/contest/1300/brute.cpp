#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int nbit(int n)
{
    int c = 0;
    while(n)
    {
        if(n & 1)
            c++;
        n = n / 2;
    }
    return c;
}

int main()
{
    FASTIO;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)   cin >> x;
    bool ok = true;
    vector<bool> done(n, false);
    vector<int> temp;
    auto it = max_element(all(arr));
    temp.push_back(*it);
    int ans = *it;
    int in = it - arr.begin();
    done[in] = true;
    while(true)
    {
        bool left = false;
        for(bool x : done)
            if(!x)
                left = true;
        if(!left)
            break;
        int ind = -1;
        int mx = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(done[i])
                continue;
            if(mx < (ans | arr[i]) - arr[i])
            {
                mx = (ans | arr[i]) - arr[i];
                ind = i;

            }
        }
        ans = (ans | arr[ind]) - arr[ind];
        temp.push_back(arr[ind]);
        done[ind] = true;
    }
    for(int x : temp)
        cout << x << " ";
    return 0;
}