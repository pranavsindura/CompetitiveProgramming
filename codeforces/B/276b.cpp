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
    int hash[26] = {0};
    for(char x : s)
        hash[x - 'a']++;
    int c = 0;
    for(int i = 0; i < 26; i++)
        if(hash[i] & 1)
            c++;
    if(c & 1 || (c == 0))
        cout << "First";
    else
        cout << "Second";
    return 0;
}
