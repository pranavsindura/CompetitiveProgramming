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

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    if(n % k)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> freq(26);
    for(char x : s)
        freq[x - 'a']++;
    bool same = true;
    for(int i = 0; i < 26; i++)
        same &= freq[i] % k == 0;

    if(same)
    {
        cout << s << endl;
        return;
    }

    freq.assign(26, 0);
    int p = -1, place = -1;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 25; j > (s[i] - 'a'); j--)
        {
            sum -= (k - (freq[j] % k)) % k;
            freq[j]++;
            sum += (k - (freq[j] % k)) % k;

            if(sum <= n - i - 1 && (n - i - 1 - sum) % k == 0)
                p = i, place = j;

            sum -= (k - (freq[j] % k)) % k;
            freq[j]--;
            sum += (k - (freq[j] % k)) % k;
        }
        sum -= (k - (freq[s[i] - 'a'] % k)) % k;
        freq[s[i] - 'a']++;
        sum += (k - (freq[s[i] - 'a'] % k)) % k;
    }

    if(p == -1)
    {
        cout << -1 << endl;
        return;
    }

    string ans;
    s[p] = char(97 + place);
    freq.assign(26, 0);
    for(int i = 0; i <= p; i++)
        freq[s[i] - 'a']++, ans += s[i];

    string rem;
    for(int i = 0; i < 26; i++)
        rem += string((k - freq[i] % k) % k, char(97 + i));
    rem  = string(n - ln(ans) - ln(rem), 'a') + rem;
    ans += rem;

    assert(ln(ans) == n);

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
