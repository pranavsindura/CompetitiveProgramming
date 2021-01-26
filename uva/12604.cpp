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

char shift(char x, int s, string &alpha, vector<int> &pos_of)
{
    int pos = pos_of[int(x)];
    pos = (pos - s + ln(alpha)) % ln(alpha);
    return alpha[pos];
}

vector<int> compute_prefix(string &s)
{
    int n = ln(s);
    vector<int> longest_prefix(n);
    for(int i = 1, k = 0; i < n; i++)
    {
        while(k && s[i] != s[k])
            k = longest_prefix[k - 1];
        if(s[i] == s[k])
            k++;
        longest_prefix[i] = k;
    }
    return longest_prefix;
}

void cp()
{
    string alpha, word, text;
    cin >> alpha >> word >> text;

    vector<int> pos_of(256, -1);
    for(int i = 0; i < ln(alpha); i++)
        pos_of[int(alpha[i])] = i;

    vector<int> matches;

    vector<int> longest_prefix = compute_prefix(word);

    for(int i = 0; i < ln(alpha); i++)
    {
        string s;
        for(char x : text)
            s += shift(x, i, alpha, pos_of);

        int cnt = 0;
        for(int j = 0, k = 0; j < ln(s); j++)
        {
            while(k && word[k] != s[j])
                k = longest_prefix[k - 1];
            if(word[k] == s[j])
                k++;
            if(k == ln(word))
                cnt++, k = longest_prefix[k - 1];
        }
        if(cnt == 1)
            matches.pb(i);
    }

    if(matches.empty())
        cout << "no solution\n";
    else if(sz(matches) == 1)
    {
        cout << "unique: " << matches.front() << endl;
    }
    else
    {
        cout << "ambiguous: ";
        for(int i = 0; i < sz(matches); i++)
        {
            if(i)
                cout << " ";
            cout << matches[i];
        }
        cout << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}