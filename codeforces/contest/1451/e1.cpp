#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

int AND(int i, int j)
{
    cout << "AND " << i << " " << j << endl;
    cout.flush();
    int x;
    cin >> x;
    if(x == -1)
        exit(0);
    return x;
}

int OR(int i, int j)
{
    cout << "OR " << i << " " << j << endl;
    cout.flush();
    int x;
    cin >> x;
    if(x == -1)
        exit(0);
    return x;
}

int XOR(int i, int j)
{
    cout << "XOR " << i << " " << j << endl;
    cout.flush();
    int x;
    cin >> x;
    if(x == -1)
        exit(0);
    return x;
}

void cp()
{
    int n;
    cin >> n;
    int xor13 = XOR(1, 3);
    int and13 = AND(1, 3);
    int sum13 = xor13 + and13 * 2;
    int xor23 = XOR(2, 3);
    int and23 = AND(2, 3);
    int sum23 = xor23 + and23 * 2;
    int xor12 = xor13 ^ xor23;
    int and12 = AND(1, 2);
    int sum12 = xor12 + and12 * 2;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        int j = xor12 ^ i;
        int k = xor13 ^ i;
        if(i + j == sum12 && i + k == sum13 && j + k == sum23)
            arr[0] = i, arr[1] = j, arr[2] = k;
    }
    for(int i = 3; i < n; i++)
    {
        int x = XOR(1, i + 1);
        arr[i] = x ^ arr[0];
    }
    cout << "! ";
    for(int x : arr)
        cout << x << " ";
    cout << endl;
    cout.flush();
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