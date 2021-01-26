#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n, start = -1, end = -1, rc = 0, lc = 0;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'R')
            rc++;
        else if(s[i] == 'L')
            lc++;
    }
    if(rc)
    {
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'R' && start == -1)
                start = i + 1, end = i + 1;
            else if(s[i] == 'R')
                end++;
        }
        if(!lc)
            end++;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'L' && start == -1)
                start = i + 1, end = i + 1;
            else if(s[i] == 'L')
                end++;
        }
        swap(start, end);
        end--;
    }
    cout << start << " " << end;
    return 0;
}