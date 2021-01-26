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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

vector<string> words;
set<string> articles = {"a", "the"};
set<string> nouns = {"tom", "jerry", "goofy", "mickey", "jimmy", "dog", "cat", "mouse"};
set<string> verbs = {"hate", "like", "know", "love", "hates", "likes", "knows", "loves"};

bool noun(int i, int j)
{
    return (i == j) && nouns.count(words[i]);
}

bool article(int i, int j)
{
    return (i == j) && articles.count(words[i]);
}

bool verb(int i, int j)
{
    return (i == j) && verbs.count(words[i]);
}

bool actor(int i, int j)
{
    if(i == j)
        return noun(i, j);
    else if(i + 1 == j)
        return article(i, i) & noun(j, j);
    else
        return false;
}

bool active_list(int i, int j)
{
    bool ok = actor(i, j);
    // find and
    for(int k = i + 1; k < j; k++)
        if(words[k] == "and")
            ok |= active_list(i, k - 1) & actor(k + 1, j);
    return ok;
}

bool action(int i, int j)
{
    bool ok = false;
    for(int k = i; k < j; k++)
    {
        for(int l = k + 1; l < j; l++)
        {
            //[i, k] [k+1, l] [l+1, j]
            ok |= active_list(i, k) & verb(k + 1, l) & active_list(l + 1, j);
        }
    }
    return ok;
}

bool statement(int i, int j)
{
    bool ok = action(i, j);
    // find comma
    for(int k = i + 1; k < j; k++)
        if(words[k] == ",")
            ok |= statement(i, k - 1) & action(k + 1, j);
    return ok;
}

void cp()
{
    string s;
    while(getline(cin, s))
    {
        words.clear();
        string x;
        stringstream ss(s);
        while(ss >> x)
            words.pb(x);
        bool ok = statement(0, sz(words) - 1);
        cout << (ok ? "YES I WILL\n" : "NO I WON\'T\n");
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}