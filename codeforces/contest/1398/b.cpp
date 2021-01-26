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
    string s;
    cin >> s;
    bool done = false;
    bool turn = false;
    int score[2] = {0};
    int n = ln(s);
    while(!done)
    {
        done = true;
        int mxlen = 0;
        int i = -1, j = -1;
        int l = 0, r = 0;
        while(l < n)
        {
            while(l < n && s[l] == '0')
                l++;
            r = l;
            while(r + 1 < n && s[r + 1] == '1')
                r++;
            if(r < n && r - l + 1 > mxlen)
                mxlen = r - l + 1, i = l, j = r, done = false;
            l = r + 1;
        }
        score[turn] += mxlen;
        string temp;
        for(int k = 0; k < i; k++)
            temp += s[k];
        for(int k = j + 1; k < n; k++)
            temp += s[k];
        s = temp;
        n = ln(s);
        turn ^= 1;
    }
    cout << score[0] << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}