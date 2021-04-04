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
const int MAXN = 1e6 + 5;

string get(string &ans, string &t, vector<int> &freq, vector<int> &dig)
{
    string Left, Right;
    for(int i = 0; i < 10; i++)
    {
        if(string(freq[i] - dig[i], 48 + i) + t < t + string(freq[i] - dig[i], 48 + i))
            Left += string(freq[i] - dig[i], 48 + i);
        else
            Right += string(freq[i] - dig[i], 48 + i);
    }
    ans = ans + Left + t + Right;
    return ans;
}

void cp()
{
    string s, t;
    cin >> s >> t;
    vector<int> freq(10);
    for(char x : s) freq[x - '0']++;
    for(char x : t) freq[x - '0']--;
    for(int L = 1; L < MAXN; L++)
    {
        vector<int> dig(10);
        int temp = L;
        while(temp) dig[temp % 10]++, temp /= 10;
        bool ok = true;
        for(int i = 0; i < 10; i++)
            ok &= dig[i] <= freq[i];
        int total = 0;
        for(int i = 0; i < 10; i++)
            total += freq[i] - dig[i];
        ok &= total + ln(t) == L;

        if(!ok) continue;

        string ans;

        if(L > 1) // must have non leading zero
        {
            for(int i = 1; i < 10 && ans.empty(); i++)
                if(freq[i] > dig[i])
                    ans += char(48 + i), freq[i]--;
            if(ans.empty()) // try t
            {
                if(t.front() != '0')
                {
                    ans += t, t = "";
                    cout << get(ans, t, freq, dig) << endl;
                }
                else
                    continue;
            }
            else // check if t is better
            {
                if(t.front() != '0')
                {
                    string A = get(ans, t, freq, dig);
                    freq[ans.front() - '0']++;
                    ans = t, t = "";
                    string B = get(ans, t, freq, dig);
                    cout << min(A, B) << endl;
                }
                else
                    cout << get(ans, t, freq, dig) << endl;
            }
        }
        else
            cout << get(ans, t, freq, dig) << endl;
        return;
    }
    assert(false);
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
