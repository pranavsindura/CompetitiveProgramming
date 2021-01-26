#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
char map[100][100];
void dfs(int x, int y) {
    if(map[x][y] == 'X' || map[x][y] == '#')
        return ;
    map[x][y] = '#';
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}
int main() {
    int t, i, j;
    scanf("%d ", &t);
    while(t--) {
        int n = 0;
        while(gets(map[n])) {
            if(map[n][0] == '_')
                break;
            n++;
        }
        for(i = 0; i < n; i++) {
            for(j = 0; map[i][j]; j++) {
                if(map[i][j] == '*')
                    dfs(i, j);
            }
        }
        for(i = 0; i <= n; i++)
            puts(map[i]);
    }
    return 0;
}