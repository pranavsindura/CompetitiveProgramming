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
    string s;
    cin >> s;
    if(s == "0")
    {
        cout << 0;
        return 0;
    }
    int ans;
    bitset<101> b(s);
    if(b.count() > 1)
        ans = ((int)s.length() + 1) / 2;
    else
        ans = ((int)s.length()) / 2;
    cout << ans;
    return 0;
}