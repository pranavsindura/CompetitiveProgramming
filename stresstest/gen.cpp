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
#define get(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

// Build log2
int lg[MAXN];
void init()
{
    lg[1] = 0;
    for(int i = 2; i < MAXN; i++)
        lg[i] = lg[i / 2] + 1;
}

using ftype = int;
const int K = 25; // Enough for any array
ftype stmax[MAXN][K + 1];
ftype stmin[MAXN][K + 1];

void build_max(vector<ftype> &arr)
{
    int n = sz(arr);
    for(int i = 0; i < n; i++)
        stmax[i][0] = arr[i];

    for(int j = 1; j <= K; j++)
        for(int i = 0; i + (1 << (j - 1)) < n; i++)
            stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
}
void build_min(vector<ftype> &arr)
{
    int n = sz(arr);
    for(int i = 0; i < n; i++)
        stmin[i][0] = arr[i];

    for(int j = 1; j <= K; j++)
        for(int i = 0; i + (1 << (j - 1)) < n; i++)
            stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
}

// Query for idempotent Functions
ftype querymax(int L, int R)
{
    int j = lg[R - L + 1];
    return max(stmax[L][j], stmax[R - (1 << j) + 1][j]);
}
ftype querymin(int L, int R)
{
    int j = lg[R - L + 1];
    return min(stmin[L][j], stmin[R - (1 << j) + 1][j]);
}

int main()
{
    srand(time(NULL));
    init();
    vector<int> Nval, Mval;
    int sumn = 0, summ = 0;
    while(sumn <= 1e6 && summ <= 1e6)
    {
        int N = get(1, 1000);
        int M = get(1, 1000);
        Nval.push_back(N);
        Mval.push_back(M);
        sumn += N;
        summ += M;
    }
    Nval.pop_back(), Mval.pop_back();

    int TC = sz(Nval);
    cout << TC << endl;
    while(TC--)
    {
        int N = Nval[TC];
        int M = Mval[TC];
        int MAXH = get(1, 1000000000);
        vector<int> L, R, A, B;

        bool is_random = get(1, 100) <= 5;

        if(is_random)
        {
            for(int i = 0; i < M; i++)
            {
                L.push_back(get(1, N));
                R.push_back(get(L.back(), N));
                A.push_back(get(1, MAXH));
                B.push_back(get(A.back(), MAXH));
            }
        }
        else
        {
            vector<int> MN, MX;
            for(int i = 0; i < N; i++)
                MN.push_back(get(1, MAXH)), MX.push_back(get(MN.back(), MAXH));
            build_min(MN);
            build_max(MX);

            for(int i = 0; i < M; i++)
            {
                L.push_back(get(1, N));
                R.push_back(get(L.back(), N));
                A.push_back(get(1, querymin(L.back() - 1, R.back() - 1)));
                B.push_back(get(querymax(L.back() - 1, R.back() - 1), MAXH));
            }
        }

        cout << N << endl;
        cout << MAXH << endl;
        cout << M << endl;
        for(int i = 0; i < M; i++)
            cout << L[i] << " \n"[i == M - 1];
        for(int i = 0; i < M; i++)
            cout << R[i] << " \n"[i == M - 1];
        for(int i = 0; i < M; i++)
            cout << A[i] << " \n"[i == M - 1];
        for(int i = 0; i < M; i++)
            cout << B[i] << " \n"[i == M - 1];
    }
}
