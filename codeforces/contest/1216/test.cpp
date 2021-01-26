#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
bool valid(string s, int l, int r, int prevones, int currpartlen, int prevpartlen);
void part(string s, int l, int r, int prevones, int currpartlen, int prevpartlen);
ll c = 0;
int pre[5005];
int dp[2500][5000];

void back(string s, int n)
{

    for(int i=n-1;i>=0;i--)
    {
        if(s[i] == '1')
        {
            c++;
            c%=mod;
        }
    }
}

int main()
{
    int n;
    string s;
    scanf("%d", &n);
    // for(int i=0; i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //         c++;
    //     c%=mod;
    // }
    cin >> s;
    pre[0] = s[0] - '0';
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + (s[i] - '0');
    for (int i = 0; i < n; i++)
        cout << pre[i];
    cout << endl
         << s << endl;
        // back(s, n);
        part(s,0,n-1, 0, 1, 1);
    cout << ::c;
    return 0;
}

bool valid(string s, int l, int r, int prevones, int currpartlen, int prevpartlen)
{
    if (s[0] == '0')
        return false;
    else
    {
        int currones;
        if (l != 0)
            currones = pre[r] - pre[l - 1];
        else
            currones = pre[r];

        if (prevones <= currones && prevpartlen <= currpartlen)
            // return true; 
        {cout<<s<<endl;return true;}
        else
            return false;
    }
}

void part(string s, int l, int r, int prevones, int currpartlen, int prevpartlen)
{
    if (s.length())
    {
        if (valid(s, l, r, prevones, currpartlen, prevpartlen))
        {
            c++;
            c %= mod;
            for (int i = prevpartlen; i <= s.length() / 2; i++)
            {
                string temp = s;
                temp.erase(0, i);
                int p;
                if (l)
                    p = pre[l + i - 1] - pre[l - 1];
                else
                    p = pre[i - 1];
                part(temp, l + i, r, p, i, currpartlen);
            }
        }
    }
}