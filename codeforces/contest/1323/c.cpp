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
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
int main()
{
    FASTIO;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int bal[n];
    bal[0] = (s[0] == '(' ? 1 : -1);
    for(int i = 1; i < n; i++)
    {
        bal[i] = bal[i - 1] + (s[i] == '(' ? 1 : -1);
    }
    if(bal[n - 1])
    {
        cout << -1;
        return 0;
    }
    int c = 0;
    for(int i = 1; i < n; i++)
    {
        if((bal[i - 1] < 0 && bal[i] <= 0) || (bal[i - 1] <= 0 && bal[i] < 0))
        {
            c++;
        }
    }
    if(s[0] == '(')
        cout << c;
    else
        cout << c + 1;
    return 0;
}