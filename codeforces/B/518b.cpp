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
    string a, b;
    cin >> a >> b;
    map<char, int> mb;
    for(char x : b)
        mb[x]++;
    int yay = 0, whoops = 0;
    vector<bool> vis(ln(a), false);
    for(int i = 0; i < ln(a); i++)
    {
        char x = a[i];
        if(mb[x])
            yay++, mb[x]--, vis[i] = true;
    }
    for(int i = 0; i < ln(a); i++)
    {
        if(vis[i])
            continue;
        char x = a[i], y = (x >= 'a' && x <= 'z') ? char(x - 'a' + 65) : char(x - 'A' + 97);
        if(mb[y])
            whoops++, mb[y]--;
    }
    cout << yay << " " << whoops << endl;
    return 0;
}