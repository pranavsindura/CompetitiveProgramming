#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

set<string> simple, comp;
void getSimple();
void getComplex();

void cp()
{
    string s;
    cin >> s;
    getSimple();
    getComplex();

    string ans;

    int i = 0, n = ln(s);
    while(i < n)
    {
        if(!isalpha(s[i]))
        {
            ans += string(1, s[i]) + " ";
            i++;
            continue;
        }

        if(i + 1 < n)
        {
            if(s[i] == s[i + 1]) // double consonant
            {
                ans += string(1, s[i]) + " ";
                i++;
                continue;
            }

            if(i + 2 < n)
            {
                string t = s.substr(i, 3);
                if(simple.count(t)) // 3 length simple
                {
                    ans += t + " ";
                    i += 3;
                    continue;
                }
            }

            string t = s.substr(i, 2);
            if(simple.count(t)) // 2 length simple
            {
                ans += t + " ";
                i += 2;
                continue;
            }

            t = s[i];
            if(simple.count(t)) // single simple
            {
                ans += t + " ";
                i++;
                continue;
            }

            t = s.substr(i, 2); // 2 letter compound
            if(comp.count(t))
            {
                ans += t + " ";
                i += 2;
                continue;
            }

            t = s.substr(i, 3); // 3 letter compound
            if(comp.count(t))
            {
                ans += t + " ";
                i += 3;
                continue;
            }

            assert(false); // nothing?
        }
        else
            ans += string(1, s[i]) + " ", assert(simple.count(string(1, s[i]))), i++;
    }

    ans.pop_back();
    cout << ans << endl;
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

void getComplex()
{
    comp.insert("kya");
    comp.insert("kyu");
    comp.insert("kyo");

    comp.insert("gya");
    comp.insert("gyu");
    comp.insert("gyo");

    comp.insert("sha");
    comp.insert("shu");
    comp.insert("sho");

    comp.insert("ja");
    comp.insert("ju");
    comp.insert("jo");

    comp.insert("cha");
    comp.insert("chu");
    comp.insert("cho");

    comp.insert("dya");
    comp.insert("dyu");
    comp.insert("dyo");

    comp.insert("nya");
    comp.insert("nyu");
    comp.insert("nyo");

    comp.insert("hya");
    comp.insert("hyu");
    comp.insert("hyo");

    comp.insert("bya");
    comp.insert("byu");
    comp.insert("byo");

    comp.insert("pya");
    comp.insert("pyu");
    comp.insert("pyo");

    comp.insert("mya");
    comp.insert("myu");
    comp.insert("myo");

    comp.insert("rya");
    comp.insert("ryu");
    comp.insert("ryo");
}

void getSimple()
{
    simple.insert("a");
    simple.insert("i");
    simple.insert("u");
    simple.insert("e");
    simple.insert("o");

    simple.insert("ka");
    simple.insert("ki");
    simple.insert("ku");
    simple.insert("ke");
    simple.insert("ko");

    simple.insert("ga");
    simple.insert("gi");
    simple.insert("gu");
    simple.insert("ge");
    simple.insert("go");

    simple.insert("sa");
    simple.insert("shi");
    simple.insert("su");
    simple.insert("se");
    simple.insert("so");

    simple.insert("za");
    simple.insert("ji");
    simple.insert("zu");
    simple.insert("ze");
    simple.insert("zo");

    simple.insert("ta");
    simple.insert("chi");
    simple.insert("tsu");
    simple.insert("te");
    simple.insert("to");

    simple.insert("da");
    simple.insert("di");
    simple.insert("dzu");
    simple.insert("de");
    simple.insert("do");

    simple.insert("na");
    simple.insert("ni");
    simple.insert("nu");
    simple.insert("ne");
    simple.insert("no");

    simple.insert("ha");
    simple.insert("hi");
    simple.insert("fu");
    simple.insert("he");
    simple.insert("ho");

    simple.insert("ba");
    simple.insert("bi");
    simple.insert("bu");
    simple.insert("be");
    simple.insert("bo");

    simple.insert("pa");
    simple.insert("pi");
    simple.insert("pu");
    simple.insert("pe");
    simple.insert("po");

    simple.insert("ma");
    simple.insert("mi");
    simple.insert("mu");
    simple.insert("me");
    simple.insert("mo");

    simple.insert("ya");
    simple.insert("yu");
    simple.insert("yo");

    simple.insert("ra");
    simple.insert("ri");
    simple.insert("ru");
    simple.insert("re");
    simple.insert("ro");

    simple.insert("wa");
    simple.insert("wo");
    simple.insert("we");
    simple.insert("wi");

    simple.insert("n");
}