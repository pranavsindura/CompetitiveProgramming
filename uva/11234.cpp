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

struct node
{
    char data;
    node *left, *right;
    node(): data('#'), left(NULL), right(NULL) {}
    node(char data, node *left, node *right): data(data), left(left), right(right) {}
};

void clean(node *root)
{
    if(root == NULL) return;
    clean(root->left);
    clean(root->right);
    delete root;
}

void cp()
{
    string exp;
    cin >> exp;
    stack<node *> st;
    for(char x : exp)
    {
        if(isupper(x))
        {
            node *a = st.top();
            st.pop();
            node *b = st.top();
            st.pop();
            node *p = new node(x, b, a);
            st.push(p);
        }
        else
        {
            node *p = new node(x, NULL, NULL);
            st.push(p);
        }
    }

    node *root = st.top();
    st.pop();

    string ans;
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *u = q.front();
        q.pop();
        ans += u->data;
        if(u->left) q.push(u->left);
        if(u->right) q.push(u->right);
    }
    clean(root);

    reverse(all(ans));
    cout << ans << endl;
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

