#include <bits/stdc++.h>
#define ll long long int
#define lim 10000000.0
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;
double fpow(double x, ll y)
{
    double res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}
bool check(char x)
{
    if ((x == 'a') || (x == 'e') || (x == 'i') || (x == 'o') || (x == 'u'))
        return true;
    else
        return false;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        int l;
        cin >> l;
        vector<string> arr;
        for (int i = 0; i < l; i++)
        {
            string a;
            cin >> a;
            arr.push_back(a);
        }
        vector<string> alice, bob;
        for (int i = 0; i < arr.size(); i++)
        {
            bool flag = false;
            for(int j=0;j<arr[i].length()-1;j++)
            {
                if(check(arr[i][j])  == check(arr[i][j+1])  && !check(arr[i][j]))
                {
                    flag = true;
                    break;
                }
            }
            for(int j=0;j<arr[i].length()-2;j++)
            {
                if(check(arr[i][j])  == check(arr[i][j+2])  && !check(arr[i][j]) && check(arr[i][j+1]))
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                bob.push_back(arr[i]);
            }
            else
            {
                alice.push_back(arr[i]);
            }
        }
        int sizea, sizeb;
        sizea = alice.size();
        sizeb = bob.size();
        ll hasha[sizea][26] = {0}, hashb[sizeb][26] = {0}, ha[26] = {0}, hb[26] = {0}, counta[26] = {0}, countb[26] = {0};
        for (int i = 0; i < alice.size(); i++)
        {
            for (int j = 0; j < alice[i].length(); j++)
            {
                hasha[i][alice[i][j] - 'a']++;
                ha[(alice[i][j] - 'a')]++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < sizea; j++)
            {
                if (hasha[j][i] > 0)
                {
                    counta[i]++;
                }
            }
        }
        for (int i = 0; i < bob.size(); i++)
        {
            for (int j = 0; j < bob[i].length(); j++)
            {
                hashb[i][bob[i][j] - 'a']++;
                hb[bob[i][j] - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < sizeb; j++)
            {
                if (hashb[j][i] > 0)
                {
                    countb[i]++;
                }
            }
        }
        for (int i = 0; i < 26; i++)
        {
        	if(!counta[i])
        	{
        		counta[i]=1;
        		ha[i]=1;
        	}
        	if(!countb[i])
        	{
        		countb[i]=1;
        		hb[i]=1;
        	}
        }
        double p=0;
        for (int i = 0; i < 26; i++)
        {
			 p += log10(counta[i]*1.0) + sizeb*1.0*log10(hb[i]*1.0);
			 p -= log10(countb[i]*1.0);
			 p -= sizea*1.0*log10(ha[i]*1.0);
        }
        if (p < 7.0)
        {
            cout << fixed << setprecision(10) << pow(10.0, p) << endl;
        }
        else
        {
        	cout << "Infinity" << endl;
        }
    }
    return 0;
}