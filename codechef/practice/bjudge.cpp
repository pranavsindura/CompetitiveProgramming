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
    int n, m;
    cin >> n >> m;
    vector<int> D(n);
    for(int &x : D)
        cin >> x;
    vector<vector<int>> A(n, vector<int>(m)), B = A;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> A[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> B[i][j];

    vector<int> tests(m, 1);
    vector<int> TL(m, 1);
    for(int i = 0; i < n; i++)
    {
        if(!D[i]) continue;
        for(int j = 0; j < m; j++)
        {
            tests[j] &= B[i][j];
            TL[j] = max(TL[j], A[i][j]);
        }
    }

    vector<int> picked;
    for(int i = 0; i < m; i++) if(tests[i]) picked.push_back(i);
    sort(all(picked), [&](int a, int b)
    {
        return TL[a] < TL[b];
    });

    auto check = [&]()
    {
        int T = picked.empty() ? 1 : TL[picked.back()];
        bool ok = true;
        for(int i = 0; i < n; i++)
        {
            bool pass = true;
            for(int x : picked)
                pass &= B[i][x] && A[i][x] <= T;
            ok &= pass == D[i];
        }
        return ok;
    };

    while(!picked.empty() && !check())
        picked.pop_back();

    if(check())
    {
        cout << "YES\n";
        int T = picked.empty() ? 1 : TL[picked.back()];
        int K = sz(picked);
        cout << T << " " << K << endl;
        for(int x : picked)
            cout << x + 1 << " ";
        cout << endl;
    }
    else
        cout << "NO\n";
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

