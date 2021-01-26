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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 2e2 + 5;

int get(string n)
{
    int num = 0;
    for(char x : n)
        num = num * 10 + (x - '0');
    return num;
}

struct cmp
{
    const bool operator()(const pi &a, const pi &b)const
    {
        if(a.ff == b.ff)
            return a.ss < b.ss;
        else
            return a.ff > b.ff;
    }
};

string a, b;

int p[MAXN][MAXN], q[MAXN][MAXN], res[MAXN][MAXN];
set<pi, cmp> pp, pq, pres;

void parse(string &s, set<pi, cmp> &powers, int coeff[MAXN][MAXN])
{
    if(s.front() != '-')
        s = "+" + s;
    int x = 0, y = 0;
    string num;
    bool was_digit = false;

    while(!s.empty())
    {
        char c = s.back();
        s.pop_back();
        if(c == '+')
        {
            // approached a sign
            if(!was_digit) // no digit before it, number must be 1
                num = "1";
            powers.insert({x, y});
            coeff[x][y] += get(num);
            num = "", x = 0, y = 0, was_digit = 0;
        }
        else if(c == '-')
        {
            // approached a sign
            if(!was_digit) // no digit before it, number must be 1
                num = "1";
            powers.insert({x, y});
            coeff[x][y] += -get(num);
            num = "", x = 0, y = 0, was_digit = 0;
        }
        else if(c == 'x')
        {
            // approached a variable
            if(!was_digit) // no digit before it, power must be 1
                num = "1";
            // num = flip(num);
            x = get(num);
            was_digit = 0;
            num = "";
        }
        else if(c == 'y')
        {
            // approached a variable
            if(!was_digit) // no digit before it, power must be 1
                num = "1";
            y = get(num);
            was_digit = 0;
            num = "";
        }
        else
        {
            // approached a number
            was_digit = 1;
            num = c + num;
        }
    }
}

void cp()
{
    while(cin >> a && a[0] != '#')
    {
        cin >> b;
        clr(p, 0), clr(q, 0), clr(res, 0);
        pq.clear();
        pp.clear();
        pres.clear();

        parse(a, pp, p);
        parse(b, pq, q);

        for(pi u : pp)
        {
            int ax = u.ff, ay = u.ss;
            for(pi v : pq)
            {
                int bx = v.ff, by = v.ss;
                res[ax + bx][ay + by] += p[ax][ay] * q[bx][by];
                pres.insert({ax + bx, ay + by});
            }
        }

        string c, d;
        bool first = true;
        for(pi u : pres)
        {
            int x = u.ff, y = u.ss;
            int coeff = res[x][y];
            if(coeff == 0)
                continue;
            // coeff * X^x * Y^y
            int sg = (coeff > 0 ? 1 : -1);
            coeff = abs(coeff);

            if(first)
            {
                // avoid sign if +ve
                if(sg == -1)
                {
                    c += ' ';
                    d += '-';
                }
            }
            else
            {
                c += "   ";
                if(sg == 1)
                    d += " + ";
                else
                    d += " - ";
            }
            if(coeff > 1 || (coeff == 1 && x == 0 && y == 0))
            {
                string num = to_string(coeff);
                c += string(ln(num), ' ');
                d += num;
            }

            if(x > 1)
            {
                c += ' ';
                d += 'x';
                string me = to_string(x);
                c += me;
                d += string(ln(me), ' ');
            }
            else if(x == 1)
                c += ' ', d += 'x';

            if(y > 1)
            {
                c += ' ';
                d += 'y';
                string me = to_string(y);
                c += me;
                d += string(ln(me), ' ');
            }
            else if(y == 1)
                c += ' ', d += 'y';

            first = false;
        }

        if(first)
        {
            cout << endl;
            cout << 0 << endl;
            continue;
        }

        while(ln(c) < ln(d))
            c += ' ';
        while(ln(d) < ln(c))
            d += ' ';

        cout << c << endl;
        cout << d << endl;
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