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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int found[26] = {0}, hash[26] = {0};
    map<char, bool> instring, inkey;
    for(int i = 0; i < 26; i++)
    {
        found[i] = -1;
        instring[char(i + 97)] = false;
        inkey[char(i + 97)] = false;
    }
    for(int i = 0; i < n; i++)
    {
        // found[s[i]-'a']=0;
        instring[s[i]] = true;
    }
    for(int i = 0; i < k; i++)
    {
        char x;
        cin >> x;
        found[x - 'a'] = 1;
        inkey[x] = true;
    }
    ll count = 0;
    ll c = 0;
    for(int i = 0; i < n; i++)
    {
        if(inkey[s[i]])
            c++;
        else
        {
            count += c * (c + 1) / 2;
            c = 0;
        }
    }
    count += c * (c + 1) / 2;

    cout << count;
    return 0;
}