#include<iostream>
#include<iomanip>
#include<string.h>
#include<math.h>
#define endl '\n'
using namespace std;
const double eps = 1e-9;
// POJ is old, do w/o template

/*
	T * M * M * 2 * 2 => 1000 * 30 * 30 * 2 * 2 => 36 * 10^5 => 3.6 * 10^6
	Team no, Problem no, solved problems, atleast 1, atleast N
	validity? atleast 1 && atleast N

	Recursion is nice for specific cases
	But we can build table and then use math

	Try with Bottom up -> Faster

	Prob that all teams solve atleast 1 problem
	A = product(sum(ith team solving [1, M] problems))

	Prob that all teams solve atleast 1 problem and atleast one team solving atleast N
	Total - No team solving atleast N problems

	No team solving atleast N problems
	B = product(sum(ith team solving [1, N-1] problems))

	Ans = A - B
*/
int M, N, T;
double P[1005][35];
double dp[1002][32][32];
// double dp[1002][32][32][2][2];

// double solve(int i, int j, int solved, bool s1, bool sn)
// {
//     if(i == T) return s1 && sn;
//     if(j == M) return solve(i + 1, 0, 0, s1 && solved > 0, sn || solved >= N);

//     double &ret = dp[i][j][solved][s1][sn];
//     if(fabs(ret + 1) > eps) return ret;

//     double ans = 0;
//     // solve the problem
//     ans += P[i][j] * solve(i, j + 1, solved + 1, s1, sn);
//     // dont solve
//     ans += (1. - P[i][j]) * solve(i, j + 1, solved, s1, sn);

//     return ret = ans;
// }

void cp()
{
    while(cin >> M >> T >> N && N + M + T)
    {
        for(int i = 0; i < T; i++)
            for(int j = 0; j < M; j++)
                cin >> P[i][j];

        for(int i = 0; i <= T; i++)
            for(int j = 0; j <= M; j++)
                for(int k = 0; k <= M; k++)
                    dp[i][j][k] = 0;

        for(int i = 0; i < T; i++)
        {
            dp[i][0][0] = 1;
            for(int j = 0; j < M; j++)
            {
                for(int k = 0; k <= j; k++)
                {
                    // solve the problem
                    dp[i][j + 1][k + 1] += P[i][j] * dp[i][j][k];
                    // dont solve
                    dp[i][j + 1][k] += (1. - P[i][j]) * dp[i][j][k];
                }
            }
        }

        double A = 1, B = 1;
        for(int i = 0; i < T; i++)
        {
            double a = 0, b = 0;
            for(int k = 1; k <= M; k++)
                a += dp[i][M][k];
            for(int k = 1; k < N; k++)
                b += dp[i][M][k];
            A *= a;
            B *= b;
        }

        cout << fixed << setprecision(3);
        cout << A - B << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

