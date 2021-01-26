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

struct node
{
    int num, len, idx;
    node(): num(-1), len(-1), idx(-1) {}
    node(int num, int len, int idx): num(num), len(len), idx(idx) {}
    const bool operator<(const node &v)const
    {
        if(len == v.len)
            return idx < v.idx;
        else
            return len > v.len;
    }
};

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    // List for combining 2 nodes on either side of deleted node
    list<node> seg;
    // Set for getting the Longest consecutive and left most segment
    set<node> mxlen;
    // Keeps track of node's location in the list
    map<node, list<node>::iterator> it_pos;

    // Getting num,len,idx if each consecutive segment
    int i = 0, j = 0;
    while(i < n)
    {
        int cnt = 0;
        while(j < n && arr[j] == arr[i])
            j++, cnt++;

        node v(arr[i], cnt, i);

        seg.push_front(v);
        it_pos[v] = seg.begin();
        mxlen.insert(v);

        i = j;
    }

    int op = 0;

    while(!seg.empty())
    {
        node z = *begin(mxlen);
        mxlen.erase(begin(mxlen));

        list<node>::iterator pos = it_pos[z], left = pos, right = pos;
        right++;

        it_pos.erase(z);

        // check if first or last element in list
        if(left == begin(seg) || right == end(seg))
        {
            // cannot combine any, dont touch
            seg.erase(pos);
        }
        else
        {
            left--;
            seg.erase(pos);
            // try to combine left and right of pos
            if(left->num == right->num)
            {
                // Can combine, make new node
                node v(right->num, right->len + left->len, right->idx);

                // Remove occurances of Left and Right from Map, Set and List
                mxlen.erase(mxlen.find(*left)), mxlen.erase(mxlen.find(*right));
                it_pos.erase(*right), it_pos.erase(*left);

                // Add new node
                mxlen.insert(v);
                it_pos[v] = left;

                // Replace left with new node and remove right node
                *left = v;
                seg.erase(right);
            }
        }
        op++;
    }
    cout << op;
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