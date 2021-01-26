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
    int i = 0;
    if(s[0] == '9')
        i++;
    for(; i < s.length(); i++)
    {
        int x = s[i] - '0';
        s[i] = min(x, 9 - x) + '0';
    }
    cout << s;
    return 0;
}