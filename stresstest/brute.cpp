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

int is_hill(int a, int b, int c)
{
    return a < b && b > c;
}

int is_valley(int a, int b, int c)
{
    return a > b && b < c;
}

int count_hill_valley(vector<int> &A, vector<int> &order)
{
    int N = sz(A);
    int ans = 0;
    for(int i = 1; i < N - 1; i++)
        ans += is_hill(A[order[i - 1]], A[order[i]], A[order[i + 1]]) + is_valley(A[order[i - 1]], A[order[i]], A[order[i + 1]]);
    return ans;
}

void cp()
{
    int N, Q;
    cin >> N;
    vector<int> A(N);
    for(int &x : A)
        cin >> x;
    cin >> Q;
    vector<int> Type(Q), U(Q), V(Q);
    for(int &x : Type)
        cin >> x;
    for(int &x : U)
        cin >> x;
    for(int &x : V)
        cin >> x;

    vector<int> order(N);
    iota(all(order), 0);

    // cout << count_hill_valley(A, order) << " ";
    for(int i = 0; i < Q; i++)
    {
        if(Type[i] == 1)
        {
            U[i]--;
            A[U[i]] = V[i];
        }
        else
        {
            U[i]--, V[i]--;
            int p = find(all(order), U[i]) - begin(order);
            for(int j = p; j < N - 1; j++)
                order[j] = order[j + 1];
            order[N - 1] = inf;
            int q = find(all(order), V[i]) - begin(order);
            for(int j = N - 1; j > q; j--)
                order[j] = order[j - 1];
            order[q + 1] = U[i];
        }
        cout << count_hill_valley(A, order) << " ";
    }
    cout << endl;
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
