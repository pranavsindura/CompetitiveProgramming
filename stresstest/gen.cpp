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

int main()
{
    srand(time(NULL));
    vector<int> Nval, Mval;
    int sumn = 0, summ = 0;
    while(sumn <= 1e6 && summ <= 1e6)
    {
        int N = get(1, 5);
        int M = get(1, 5);
        Nval.push_back(N);
        Mval.push_back(M);
        sumn += N;
        summ += M;
    }
    Nval.pop_back(), Mval.pop_back();

    int TC = 1;
    cout << TC << endl;
    while(TC--)
    {
        int N = Nval[TC];
        int M = Mval[TC];
        bool type_3_once = false;
        vector<int> A, Type, U, V;

        for(int i = 0; i < N; i++)
            A.push_back(get(1, 10));

        int cnt = N;
        int Q = 0;
        for(int i = 0; i < M && cnt > 0; i++)
        {
            Q++;
            Type.push_back(get(1, 3));
            type_3_once |= Type.back() == 3;
            if(Type.back() == 1) U.push_back(-1), V.push_back(-1), cnt--;
            else if(Type.back() == 2) U.push_back(get(1, cnt)), V.push_back(get(1, 10));
            else U.push_back(get(1, cnt)), V.push_back(-1);
        }

        if(!type_3_once)
        {
            Type[0] = 3;
            U[0] = get(1, N);
            V[0] = -1;
            type_3_once = true;
        }

        cout << N << endl;
        for(int i = 0; i < N; i++)
            cout << A[i] << " \n"[i == N - 1];
        cout << Q << endl;
        for(int i = 0; i < Q; i++)
            cout << Type[i] << " \n"[i == Q - 1];
        for(int i = 0; i < Q; i++)
            cout << U[i] << " \n"[i == Q - 1];
        for(int i = 0; i < Q; i++)
            cout << V[i] << " \n"[i == Q - 1];
    }
}
