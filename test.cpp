#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

char* findMax(int* arr, int size) {
	char *res = new char[MAXN];
	int p = 0;
	for(int i = 0; i < size; i++)
		if(arr[i] == 0) res[p++] = '0';
		else {
			while(arr[i]) res[p++] = char(48 + arr[i] % 10), arr[i] /= 10;
		}
	res[p] = '\0';
	sort(res, res + p);
	reverse(res, res + p);
	return res;
}

int main()
{
	int size = 4;
	int arr[] = {34, 79, 58, 64};
	cout << findMax(arr, size) << endl;
}
