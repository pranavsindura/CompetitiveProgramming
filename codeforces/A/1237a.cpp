#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
int main()
{
    FASTIO;
    int n, x, y, z;
    bool up = true;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x % 2 == 0)
        {
            x = x / 2;
        }
        else
        {
            if(up)
                x = ceil(x / 2.0);
            else
                x = floor(x / 2.0);
            up = !up;
        }
        arr.push_back(x);
    }
    for(int i : arr)
        cout << i << endl;
    return 0;
}