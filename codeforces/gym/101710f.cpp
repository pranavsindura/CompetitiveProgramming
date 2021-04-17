#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

vector<int> get_failure(string &S)
{
    vector<int> failure(ln(S));
    for(int i = 1, k = 0; i < ln(S); i++)
    {
        while(k && S[i] != S[k]) k = failure[k - 1];
        if(S[i] == S[k]) k++;
        failure[i] = k;
    }
    return failure;
}

bool find_kmp(string &text, string &p)
{
    int n = ln(p);
    vector<int> failure = get_failure(p);
    n = ln(text);
    bool found = false;
    for(int i = 0, k = 0; i < n && !found; i++)
    {
        while(k > 0 && text[i] != p[k])
            k = failure[k - 1];
        if(p[k] == text[i])
            k++;
        if(k == ln(p))
            found = true;
    }
    return found;
}

string join(string &s, string &t)
{
    string p = t + " " + s;
    // remove longest prefix of t that is suffix of s
    int n = ln(p);
    vector<int> failure = get_failure(p);
    int common = failure[n - 1];
    string res;
    for(int i = 0; i < ln(s); i++)
        res += s[i];
    for(int i = common; i < ln(t); i++)
        res += t[i];
    return res;
}

string reduce(string S)
{
    vector<int> failure = get_failure(S);
    while(failure.back()--)
        S.pop_back();
    return S;
}

void cp()
{
    string A, B;
    cin >> A >> B;

    if(find_kmp(A, B))
    {
        string S = reduce(A);
        cout << ln(S) << endl;
        cout << S << endl;
    }
    else if(find_kmp(B, A))
    {
        string S = reduce(B);
        cout << ln(S) << endl;
        cout << S << endl;
    }
    else
    {
        string S1 = reduce(join(A, B));
        string S2 = reduce(join(B, A));
        cout << min(ln(S1), ln(S2)) << endl;
        cout << (ln(S1) < ln(S2) ? S1 : S2) << endl;
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
        if(t) cout << endl;
    }
    return 0;
}
