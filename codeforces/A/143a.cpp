#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
int a, b, c, d;
bool solve(int r1, int r2, int c1, int c2, int d1, int d2)
{
    for(int i = 1; i < 10; i++)
    {
        for(int j = 1; j < 10; j++)
        {
            if(j == i)
                continue;
            for(int k = 1; k < 10; k++)
            {
                if(k == i || k == j)
                    continue;
                for(int l = 1; l < 10; l++)
                {
                    if(l == i || l == j || l == k)
                        continue;
                    if(i + j == r1 && k + l == r2 && i + k == c1 && j + l == c2 && i + l == d1 && j + k == d2)
                    {
                        a = i, b = j, c = k, d = l;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    FASTIO;
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    if(solve(r1, r2, c1, c2, d1, d2))
        cout << a << " " << b << endl << c << " " << d;
    else
        cout << -1;
    return 0;
}