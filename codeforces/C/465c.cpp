#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, p_num;
    string s;
    cin >> n >> p_num >> s;
    char p = char(97 + p_num - 1);
    if(n == 1)
    {
        char x = s[0];
        x++;
        if(x <= p)
            cout << x;
        else
            cout << "NO";
    }
    else if(n == 2)
    {
        bool found = false;
        for(char i = 'a'; i <= p && !found; i++)
        {
            for(int j = 'a'; j <= p && !found; j++)
            {
                string temp;
                temp += i;
                temp += j;
                if(temp <= s)
                    continue;
                if(i != j)
                    found = true, s = temp;
            }
        }
        if(!found)
            cout << "NO";
        else
            cout << s;
    }
    else
    {
        bool found = false;
        int pos = 0;
        char place = ' ';
        for(int i = 0; i < n; i++)
        {
            for(char x = s[i] + 1; x <= p; x++)
            {
                bool can = true;
                if(i - 1 >= 0 && s[i - 1] == x)
                    can = false;
                if(i - 2 >= 0 && s[i - 2] == x)
                    can = false;
                if(can)
                {
                    found = true, pos = i, place = x;
                    break;
                }
            }
        }
        if(!found)
        {
            cout << "NO";
            return;
        }
        s[pos] = place;
        for(int i = pos + 1; i < n; i++)
        {
            for(char x = 'a'; x <= p; x++)
            {
                bool can = true;
                if(i - 1 >= 0 && s[i - 1] == x)
                    can = false;
                if(i - 2 >= 0 && s[i - 2] == x)
                    can = false;
                if(can)
                {
                    s[i] = x;
                    break;
                }
            }
        }
        cout << s;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}