#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        ll res, k = 0, a, b;
        cin >> a >> b;
        ll num = b, flag = 1;
        while(num)
        {
            if(num % 10 != 9)
            {
                flag = 0;
            }
            k++;
            num = num / 10;
        }
        if(flag == 0)
        {
            k--;
        }
        if(k)
        {
            res = k * a;
        }
        else
        {
            res = 0;
        }
        cout << res << endl;
    }
}