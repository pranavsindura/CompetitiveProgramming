#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
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
const double PI = acos(-1.0);

void print_trim(vector<int> &arr)
{
    if(arr.empty())
    {
        cout << -1;
        return;
    }
    int zero = 0;
    for(int i = 0; i < sz(arr); i++)
        if(arr[i] == 0)
            zero++;
    if(zero == sz(arr))
    {
        cout << 0;
        return;
    }
    bool st = true;
    for(int i = 0; i < sz(arr); i++)
    {
        if(arr[i] == 0)
        {
            if(st)
            {
                //dont print
            }
            else
                cout << arr[i];
        }
        else
        {
            st = false;
            cout << arr[i];
        }
    }
}

int count_actual(vector<int> &arr)
{
    if(arr.empty())
    {
        return INT_MAX;
    }
    int zero = 0;
    for(int i = 0; i < sz(arr); i++)
        if(arr[i] == 0)
            zero++;
    if(zero == sz(arr))
    {
        return 1;
    }
    bool st = true;
    int c = 0;
    for(int i = 0; i < sz(arr); i++)
    {
        if(arr[i] == 0)
        {
            if(st)
            {
                //dont print
            }
            else
                c++;
        }
        else
        {
            st = false;
            c++;
        }
    }
    return c;
}

void cp()
{
    string s;
    cin >> s;
    int n = ln(s);
    vector<int> arr(n);
    vector<vector<int>> modulo(3);
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        arr[i] = s[i] - '0';
        total = (total + arr[i]) % 3;
        modulo[arr[i] % 3].pb(i);
    }

    int zero[n + 1], z = 0, loss[n + 1];
    zero[n] = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] == 0)
            z++, zero[i] = z;
        else
        {
            zero[i] = z;
            z = 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            loss[i] = zero[i] + 1;
        }
        else
        {
            loss[i] = 1;
        }
    }
    sort(all(modulo[0]), [&](int a, int b)
    {
        return loss[a] < loss[b];
    });
    sort(all(modulo[1]), [&](int a, int b)
    {
        return loss[a] < loss[b];
    });
    sort(all(modulo[2]), [&](int a, int b)
    {
        return loss[a] < loss[b];
    });
    if(total == 0)
    {
        cout << s;
    }
    else if(total == 1)
    {
        //find 1 with modulo == 1
        if(sz(modulo[1]) && sz(modulo[2]) > 1)
        {
            //ok
            vector<int> v1, v2;
            for(int i = 0; i < n; i++)
            {
                if(i == modulo[1][0])
                    continue;
                v1.pb(arr[i]);
            }
            int c1 = count_actual(v1);
            for(int i = 0; i < n; i++)
            {
                if(i == modulo[2][0] || i == modulo[2][1])
                    continue;
                v2.pb(arr[i]);
            }
            int c2 = count_actual(v2);
            if(c1 > c2)
            {
                print_trim(v1);
                return;
            }
            else
            {
                print_trim(v2);
                return;
            }
        }
        else if(sz(modulo[1]))
        {
            vector<int> v;
            for(int i = 0; i < n; i++)
            {
                if(i == modulo[1][0])
                    continue;
                v.pb(arr[i]);
            }
            print_trim(v);
            return;
        }

        //find 2 with modulo == 2
        else if(sz(modulo[2]) > 1)
        {
            vector<int> v;
            for(int i = 0; i < n; i++)
            {
                if(i == modulo[2][0] || i == modulo[2][1])
                    continue;
                v.pb(arr[i]);
            }
            print_trim(v);
            return;
        }
        else
        {
            //nothing can be done
            cout << -1;
            return;
        }
    }
    else
    {
        //find 1 with modulo == 2
        if(sz(modulo[2]) && sz(modulo[1]) > 1)
        {
            vector<int> v1, v2;
            for(int i = 0; i < n; i++)
            {
                if(i == modulo[2][0])
                    continue;
                v1.pb(arr[i]);
            }
            int c1 = count_actual(v1);
            for(int i = 0; i < n; i++)
            {
                if(i == modulo[1][0] || i == modulo[1][1])
                    continue;
                v2.pb(arr[i]);
            }
            int c2 = count_actual(v2);
            if(c1 > c2)
            {
                print_trim(v1);
                return;
            }
            else
            {
                print_trim(v2);
                return;
            }
        }
        else if(sz(modulo[2]))
        {
            //ok
            vector<int> v;
            for(int i = 0; i < n; i++)
            {
                if(i == modulo[2][0])
                    continue;
                v.pb(arr[i]);
            }
            print_trim(v);
            return;
        }

        //find 2 with modulo == 1
        if(sz(modulo[1]) > 1)
        {
            vector<int> v;
            for(int i = 0; i < n; i++)
            {
                if(i == modulo[1][0] || i == modulo[1][1])
                    continue;
                v.pb(arr[i]);
            }
            print_trim(v);
            return;
        }
        else
        {
            //nothing can be done
            cout << -1;
            return;
        }
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