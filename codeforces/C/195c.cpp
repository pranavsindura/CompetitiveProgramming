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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

string get_exception_id(string str)
{
    string red;
    //throw(AE)
    for(int i = 6; i < ln(str); i++)
        red += str[i];
    red.pop_back();
    return red;
}
string get_exception_caught(string str)
{
    // catch(AE,"AEinline5")
    string red;
    for(int i = 6; i < ln(str) && str[i] != ','; i++)
        red += str[i];
    return red;
}
string get_message(string str)
{
    // catch(AE,"AEsomewhere")
    string red;
    int i = 0;
    while(i < ln(str))
    {
        if(str[i] == '\"')
            break;
        else
            i++;
    }
    i++;
    while(i < ln(str) && str[i] != '"')
        red += str[i], i++;
    return red;
}

void cp()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<pair<string, int>> lines;
    vector<string> orig;
    int level = 0;
    int throw_ind = -1;
    for(int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string red;
        while(!ss.eof())
        {
            string temp;
            ss >> temp;
            red += temp;
        }
        if(red.empty())
            continue;
        orig.pb(s);
        string word;
        if(red == "try")
        {
            lines.pb({red, level});
            level++;
        }
        else
        {
            for(int i = 0; i < 5; i++)
                word += red[i];
            if(word == "throw")
            {
                throw_ind = sz(lines);
                lines.pb({red, level});
            }
            else if(word == "catch")
            {
                level--;
                lines.pb({red, level});
            }
        }
    }

    int up = throw_ind, down = throw_ind;
    level = lines[throw_ind].ss;

    string exception_id = get_exception_id(lines[throw_ind].ff);

    string ans = "Unhandled Exception";
    while(true)
    {
        if(level < 0)
            break;
        while(up >= 0 && lines[up].ss >= level)
            up--;
        while(down < sz(lines) && lines[down].ss >= level)
            down++;
        level--;
        if((up < 0) || (down >= sz(lines)))
            break;
        // arrived at try catch block
        string exception_caught = get_exception_caught(lines[down].ff);
        if(exception_caught == exception_id)
        {
            // can catch
            ans = get_message(orig[down]);
            break;
        }
    }
    cout << ans;
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