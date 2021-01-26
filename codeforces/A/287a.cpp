#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
bool check(char x)
{
    if(x == '#')
        return true;
    else
        return false;
}
int main()
{
    FASTIO;
    char arr[4][4];
    string s;
    for(int i = 0; i < 4; i++)
    {
        cin >> s;
        for(int j = 0; j < 4; j++)
            arr[i][j] = s[j];
    }
    bool yes = false;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int ch = 0, cd = 0;
            if(check(arr[i][j]))
                ch++;
            else
                cd++;
            if(check(arr[i][j + 1]))
                ch++;
            else
                cd++;
            if(check(arr[i + 1][j]))
                ch++;
            else
                cd++;
            if(check(arr[i + 1][j + 1]))
                ch++;
            else
                cd++;
            if(ch > 2 || cd > 2)
            {
                // cout << ch << " " << cd << endl;
                yes = true;
                break;
            }
        }
    }
    if(yes)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}