#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;

//Compiler version g++ 6.3.0
struct node
{
    int val;
    node *left, *right;
    node()
    {
        this->val = -1;
        this->left = NULL, this->right = NULL;
    }
} *root = NULL;
#define node struct node
bool repeat = false;
int created = 0, inp = 0;
void insert(node *root, int val, string path, int i)
{
    if(i == path.size())
    {
        if(root->val != -1)
            repeat = true;
        root->val = val;
        //cout<<"added "<<val<<endl;
    }
    else if(path[i] == 'L')
    {
        if(root->left == NULL)
        {
            created++;
            node *ptr = new node;
            root->left = ptr;
        }
        insert(root->left, val, path, i + 1);
    }
    else
    {
        if(root->right == NULL)
        {
            created++;
            node *ptr = new node;
            root->right = ptr;
        }
        insert(root->right, val, path, i + 1);
    }
}
void clean(node *root)
{
    if(root == NULL)
        return;
    clean(root->left);
    clean(root->right);
    delete root;
}
void init()
{
    clean(root);
    root = new node;
    created = 1;
    inp = 0;
    repeat = false;
}
void bfs()
{
    queue<node *> q;
    q.push(root);
    vector<int> a;
    while(!q.empty())
    {
        node *x = q.front();
        q.pop();
        if(x != NULL)
        {
            //cout<<x->val<<" ";
            a.pb(x->val);
            q.push(x->left);
            q.push(x->right);
        }
    }
    for(int i = 0; i < (int)a.size() - 1; i++)
        cout << a[i] << " ";
    cout << a.back() << endl;
}
void check()
{
    if(repeat || inp != created)
        cout << "not complete\n";
    else
        bfs();
}
int main()
{
    string s;
    init();
    while(cin >> s)
    {
        if(s == "()")
        {

            check();
            init();
            //clear root, clear inp, clear repeat, clear created
        }
        else
        {
            for(char &x : s)
            {
                if(x == '(' || x == ')' || x == ',')
                    x = ' ';
            }
            stringstream f(s);

            int val;
            string path;
            f >> val;
            f >> path;
            //cout<<val<<path<<"\n";
            inp++;
            insert(root, val, path, 0);
        }
    }
}