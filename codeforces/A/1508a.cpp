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

string match0(string &A, string &B)
{
    if(count(all(A), '0') < count(all(B), '0')) return "";
    int n = ln(A) / 2;
    string C;
    int l = 0, r = 0;
    while(l < 2 * n && r < 2 * n)
    {
        while(l < 2 * n && A[l] == '1') C += '1', l++;
        while(r < 2 * n && B[r] == '1') C += '1', r++;
        if(l == 2 * n || r == 2 * n) break;
        C += '0';
        l++, r++;
    }
    while(l < 2 * n) C += A[l++];
    while(r < 2 * n) C += B[r++];
    if(ln(C) > 3 * n) return "";
    return C;
}

string match1(string &A, string &B)
{
    if(count(all(A), '1') < count(all(B), '1')) return "";
    int n = ln(A) / 2;
    string C;
    int l = 0, r = 0;
    while(l < 2 * n && r < 2 * n)
    {
        while(l < 2 * n && A[l] == '0') C += '0', l++;
        while(r < 2 * n && B[r] == '0') C += '0', r++;
        if(l == 2 * n || r == 2 * n) break;
        C += '1';
        l++, r++;
    }
    while(l < 2 * n) C += A[l++];
    while(r < 2 * n) C += B[r++];
    if(ln(C) > 3 * n) return "";
    return C;
}

void cp()
{
    int n;
    array<string, 3> A;
    cin >> n >> A[0] >> A[1] >> A[2];
    vector<int> order = {0, 1, 2};
    string ans;
    do
    {
        string s = match0(A[order[0]], A[order[1]]);
        if(!s.empty()) ans = s;
        s = match1(A[order[0]], A[order[1]]);
        if(!s.empty()) ans = s;
    }
    while(next_permutation(all(order)));

    assert(!ans.empty());
    cout << ans << endl;
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
