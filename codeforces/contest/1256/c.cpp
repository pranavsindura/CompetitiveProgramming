#include <bits/stdc++.h>
#define ll long long int
#define ii pair<int, int>
#define iii pair<int, ii>
#define vi vector<int>
#define vii vector<ii>
using namespace std;
int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    vi arr(m);
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    vi ans(n);
    int pt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!ans[i + d])
        {
            for (int j = 0; j < arr[pt]; j++)
            {
                ans[i + j] = arr[pt];
            }
            pt++;
        }
    }
    
        return 0;
}