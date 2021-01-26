#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define eps 0.000000001
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
vector<bool> present(26, false);
vector<vector<bool>> can_order(26, vector<bool>(26, true));
vector<vector<int>> ans;
void rec(int pos, int n, vector<int> so_far)
{
    if(pos == n)
    {
        ans.pb(so_far);
    }
    else
    {

        for(int i = 0; i < 26; i++)
        {
            bool can = true;
            for(int j = 0; j < sz(so_far); j++)
            {
                if(!can_order[so_far[j]][i])
                    can = false;
            }
            if(present[i] && can)
            {
                so_far.pb(i);
                present[i] = false;
                rec(pos + 1, n, so_far);
                present[i] = true;
                so_far.pop_back();
            }
        }
    }
}

void cp()
{
    string vars;
    getline(cin, vars);
    string constraints;
    getline(cin, constraints);
    stringstream ss(vars);

    present = vector<bool>(26, false);
    can_order = vector<vector<bool>>(26, vector<bool>(26, true));
    ans.clear();

    int count_vars = 0;
    while(!ss.eof())
    {
        string x;
        ss >> x;
        count_vars++;
        present[x[0] - 'A'] = true;
    }
    stringstream ss2(constraints);

    while(!ss2.eof())
    {
        string cons;
        ss2 >> cons;
        int small = cons[0] - 'A';
        int large = cons[2] - 'A';
        can_order[large][small] = false;
    }

    rec(0, count_vars, vector<int>());

    if(sz(ans))
    {
        for(int i = 0; i < sz(ans); i++)
        {
            string line;
            for(int j = 0; j < sz(ans[i]); j++)
            {
                line += char(65 + ans[i][j]);
                line += " ";
            }
            line.pop_back();
            cout << line << endl;
        }
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        cin.ignore();
        string vars;
        getline(cin, vars);
        string constraints;
        getline(cin, constraints);
        stringstream ss(vars);
        // cout<<vars<<" "<<constraints<<endl;
        present = vector<bool>(26, false);
        can_order = vector<vector<bool>>(26, vector<bool>(26, true));
        ans.clear();

        int count_vars = 0;
        while(!ss.eof())
        {
            string x;
            ss >> x;
            count_vars++;
            present[x[0] - 'A'] = true;
        }
        stringstream ss2(constraints);

        while(!ss2.eof())
        {
            string cons;
            ss2 >> cons;
            int small = cons[0] - 'A';
            int large = cons[2] - 'A';
            can_order[large][small] = false;
        }

        rec(0, count_vars, vector<int>());

        if(sz(ans))
        {
            for(int i = 0; i < sz(ans); i++)
            {
                string line;
                for(int j = 0; j < sz(ans[i]); j++)
                {
                    line += char(65 + ans[i][j]);
                    line += " ";
                }
                line.pop_back();
                cout << line << endl;
            }
        }
        else
        {
            cout << "NO\n";
        }
        if(t)
            cout << endl;
    }
    return 0;
}