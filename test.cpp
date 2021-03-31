// #include <bits/stdc++.h>
// #define all(x)    x.begin(), x.end()
// #define allr(x)   x.rbegin(), x.rend()
// #define sz(x)     ((int)x.size())
// #define ln(x)     ((int)x.length())
// #define mp        make_pair
// #define pb        push_back
// #define ff        first
// #define ss        second
// #define endl      '\n'
// #define dbg(x)    cout << #x << ": " << x << endl;
// #define clr(x,v)  memset(x, v, sizeof(x));
// #define fix(x)    cout << setprecision(x) << fixed;
// #define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// using namespace std;

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

// using ll = long long int;
// using ld = long double;
// using pi = pair<int, int>;

// const double PI = acos(-1.0);
// const double eps = 1e-9;
// const ll mod = 1e9 + 7;
// const int inf = 1e7;
// const int MAXN = 1e5 + 5;

// void cp()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int &x : arr)
//         cin >> x;
//     int ans = 0;
//     for(int i = 0; i < n - 1; i++)
//     {
//         vector<int> X;
//         for(int j = i; j < n; j++)
//             X.push_back(arr[j]);
//         int Y = *min_element(all(X));
//         int ind = find(all(arr), Y) - begin(arr);
//         X.clear();
//         for(int j = i; j <= ind; j++)
//             X.push_back(arr[j]);
//         reverse(all(X));

//         vector<int> brr;
//         for(int j = 0; j < i; j++)
//             brr.push_back(arr[i]);
//         for(int x : X)
//             brr.push_back(x);
//         for(int j = ind + 1; j < sz(arr); j++)
//             brr.push_back(arr[j]);
//         arr = brr;
//         ans += ind - i + 1;
//     }
//     cout << ans << endl;
// }

// int main()
// {
//     FASTIO;
//     int t;
//     t = 1;
//     cin >> t;
//     for(int i = 1; i <= t; i++)
//     {
//         cout << "Case #" << i << ": ";
//         cp();
//     }
//     return 0;
// }
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
const int MAXN = 1e3 + 5;

void cp()
{
    int n, k;
    cin >> n >> k;
    int mex = n * (n + 1) / 2 - 1;
    int mn = n - 1;
    if(k >= mn && k <= mex)
    {
        int s = 0;
        for(int i = 1; i <= n; i++)
        {
            int x = i * (i + 1) / 2 - 1;
            x += n - i;
            if(k <= x)
            {
                s = i;
                break;
            }
        }

        if(s == 1)
        {
            vector<int> ans(n);
            iota(all(ans), 1);
            for(int x : ans)
                cout << x << " ";
            cout << endl;
        }
        else
        {
            vector<int> ans(n - s);
            iota(all(ans), 1);
            int cur_val = n - s + 1;
            int rem = s;
            vector<int> temp(s);
            int l = 0, r = s - 1;
            int val = sz(ans);
            int f = 1;
            while(rem > 0)
            {
                if(val + rem + rem - 2 <= k)
                {
                    val = val + rem;
                    if(f == 1)
                    {
                        temp[r] = cur_val;
                        r--;
                    }
                    else
                    {
                        temp[l] = cur_val;
                        l++;
                    }
                    f ^= 1;
                }
                else
                {
                    val++;
                    if(f == 0)
                    {
                        temp[r] = cur_val;
                        r--;
                    }
                    else
                    {
                        temp[l] = cur_val;
                        l++;
                    }
                }
                rem--;
                cur_val++;
            }
            for(int x: temp)
            	ans.push_back(x);
            for(int x : ans)
                cout << x << " ";
            cout << endl;
        }
    }
    else
        cout << "IMPOSSIBLE\n";
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}
