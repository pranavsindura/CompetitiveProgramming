#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    string s;
    cin >> s;
    while(s != "end")
    {
        char grid[3][3];
        int counto = 0, countx = 0, countdot = 0;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                grid[i][j] = s[3 * i + j];
                if(grid[i][j] == 'X')
                    countx++;
                else if(grid[i][j] == 'O')
                    counto++;
                else
                    countdot++;
            }
        }
        int winx = 0, wino = 0;
        for(int i = 0; i < 3; i++)
        {
            if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != '.')
            {
                if(grid[i][0] == 'X')
                    winx++;
                else
                    wino++;
            }
        }
        for(int i = 0; i < 3; i++)
        {
            if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != '.')
            {
                if(grid[0][i] == 'X')
                    winx++;
                else
                    wino++;
            }
        }
        if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != '.')
        {
            if(grid[0][0] == 'X')
                winx++;
            else
                wino++;
        }
        if(grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2] && grid[2][0] != '.')
        {
            if(grid[2][0] == 'X')
                winx++;
            else
                wino++;
        }

        if(winx && wino)
        {
            cout << "invalid\n";
        }
        else
        {
            if(winx)
            {
                if(countx - counto != 1)
                    cout << "invalid\n";
                else
                    cout << "valid\n";
            }
            else if(wino)
            {
                if(countx != counto)
                    cout << "invalid\n";
                else
                    cout << "valid\n";
            }
            else
            {
                if(countdot)
                {
                    cout << "invalid\n";
                }
                else
                {
                    if(countx - counto != 1)
                        cout << "invalid\n";
                    else
                        cout << "valid\n";
                }

            }
        }
        cin >> s;
    }
    return 0;
}