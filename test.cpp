#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t;



    while(t--)
    {
        cin >> n >> k;
        int a[k];
        char b[k + 1];

        for(int i = 0; i < k; i++)
        {
            cin >> a[i];
        }

        while(n--)
        {


            long long sum = 0;

            cin >> b;

            for(int j = 0; j < k; j++)
            {
                if(b[j] == '1')
                {

                    sum = sum + a[j];
                }

            }
            cout << sum;

            cout << endl;

        }
    }
}