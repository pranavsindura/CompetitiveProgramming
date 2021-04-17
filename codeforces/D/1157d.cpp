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

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    int p = 1, sum = 0;
    while(sum < n)
    {
        int take = min(n - sum, p);
        arr.push_back(take);
        sum += take;
        p++;
    }
    int m = sz(arr);
    if(k > m) cout << "NO\n";
    else if(k == m)
    {
        if(n == m * (m + 1) / 2)
        {
            cout << "YES\n";
            for(int x : arr)
                cout << x << " ";
            cout << endl;
        }
        else
            cout << "NO\n";
    }
    else
    {
        if(n != m * (m + 1) / 2)
        {
            int x = arr.back();
            arr.pop_back(), m--;
            if(x == m - 1)
            {
                for(int i = m - 1; x > 1; i--) arr[i]++, x--;
                arr.back()++;
            }
            else
                for(int i = m - 1; x > 0; i--) arr[i]++, x--;
        }

        sum = 0;
        reverse(all(arr));
        while(sz(arr) > k) sum += arr.back(), arr.pop_back();
        reverse(all(arr));
        for(int &x : arr)
            x += sum / k;

        bool found = false;
        for(int i = 0; i < sz(arr); i++)
        {
            bool ok = true;
            int x = sum % k;
            arr[i] += x;
            if(i - 1 >= 0) ok &= arr[i] <= 2 * arr[i - 1];
            if(i + 1 < sz(arr)) ok &= arr[i + 1] > arr[i];
            found |= ok;
            if(ok) break;
            arr[i] -= x;
        }
        // sanity check
        for(int i = 0; i < sz(arr) - 1; i++)
            found &= arr[i] < arr[i + 1] && arr[i + 1] <= arr[i] * 2;
        if(!found)
        {
            cout << "NO\n";
            return;
        }

        cout << "YES\n";
        for(int x : arr)
            cout << x << " ";
        cout << endl;
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
