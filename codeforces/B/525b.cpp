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
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
    {
        cin >> x;
        x--;
    }
    vector<int> f(ln(s), 0);
    for(int x : arr)
    {
        f[x]++;
        f[ln(s) - x - 1]++;
    }
    for(int i = 1; i < ln(s); i++)
        f[i] += f[i - 1];
    for(int i = 0; i < ln(s) / 2; i++)
    {
        if(f[i] % 2 == 0)
            continue;
        char temp = s[i];
        s[i] = s[ln(s) - i - 1];
        s[ln(s) - i - 1] = temp;
    }
    cout << s;
    return 0;
}