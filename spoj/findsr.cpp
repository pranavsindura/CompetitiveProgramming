#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

string str;

vector<int> compute_prefix()
{
    int n = ln(str);
    vector<int> longest_prefix(n);
    for(int i = 1, k = 0; i < n; i++)
    {
        while(k > 0 && str[i] != str[k])
            k = longest_prefix[k - 1];

        if(str[i] == str[k])
            longest_prefix[i] = ++k;
        else
            longest_prefix[i] = k;
    }
    return longest_prefix;
}

int find_second_match()
{
    vector<int> longest_prefix = compute_prefix();

    string t = str + str;
    int n = ln(t), m = n / 2;

    int matches = 0, idx = 0;

    for(int i = 0, k = 0; i < n && matches < 2; i++)
    {
        while(k > 0 && t[i] != str[k])
            k = longest_prefix[k - 1];
        if(t[i] == str[k])
            k++;
        if(k == m)
        {
            matches++, idx = i - m + 1;
            k = longest_prefix[k - 1];
        }
    }
    return idx;
}

void cp()
{
    // Approach 1 - Find the longest proper prefix that is also a suffix
    // Lets say string is made of identical blocks ABCDE
    // then the longest prefix is ABCD which matches suffix BCDE
    // this means that the length of the block is len - lenofprefix
    // now that is the F[len-1]
    // if, len % (len - F[len-1]) == 0
    // then repeats i.e. mul = len / (len - F[len-1])
    // else mul = 1

    // int n = ln(str);
    // vector<int> longest_prefix = compute_prefix();
    // int block = n - longest_prefix.back();
    // int ans = 1;
    // if(block && n % block == 0)
    //     ans = n / block;
    // cout << ans << endl;

    // Approach 2 - Repeat the string once, S' := S + S
    // Now find S in the S' using KMP
    // The first position that matches is the length of the repeating block
    // S = abcabc
    // S'= abcabcabcabc
    // Finding S in S', KMP matches it at position 0, which is the first match
    // The second match is at 3, which is the length of the repeating string!
    // len / second match is the value we need

    int n = ln(str);
    int second_match = find_second_match();
    cout << n / second_match << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(cin >> str && str[0] != '*')
    {
        cp();
    }
    return 0;
}