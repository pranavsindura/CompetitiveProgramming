/*
	MERGE TWO SORTED ARRAYS in O(1) space
	If O(n+m) space was allowed then we could do it same as Merge sort merging in O(n+m) time
	but here only O(1) space is allowed
*/
/*
	Approach 1 - Swapping over gaps O((n+m)log(n+m))

	We go swap elements with gaps, kind of like bubble sort but gaps are halved at every step
	initially gap = ceil(total_length)/2
	iterate and swap
	gap = ceil(gap/2)
	be careful of gap == 1
*/

/*
	Approach 2 - Looping and Insertion sort O(n*m)

	We iterate on the List B and want to place the largest element at the ith position of the List B
	This will be the Last number in the List A, we save it
	Now we want to find the position of the ith number of List B in List A using Insertion sort tactic
	we move every element one step back till we find a number that is < ith number of List B
	Now if anything above actually occured (i.e. List B number was already greatest so nothing will happen)
	We put greatest number at ith pos of List B, we put the ith number at the jth position in List A (Insertion Sort)
	

*/

//Approach 1
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(int &i : a)
            cin >> i;
        for(int &i : b)
            cin >> i;
        int gap = (n + m + 1) / 2;
        while(gap > 0)
        {
            int i = 0, j = gap;
            while(j < n + m)
            {
                if(i >= n && j >= n)
                {
                    //completely in second array
                    if(b[i - n] > b[j - n])
                        swap(b[i - n], b[j - n]);
                }
                else if(i < n && j >= n)
                {
                    //i in first array, j in second array
                    if(a[i] > b[j - n])
                        swap(a[i], b[j - n]);
                }
                else
                {
                    //completely in first array
                    if(a[i] > a[j])
                        swap(a[i], a[j]);
                }
                i++, j++;
            }
            if(gap <= 1)
                gap = 0;
            gap = (gap + 1) / 2;
        }
        for(int x : a)
            cout << x << " ";
        for(int x : b)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

//Approach 2
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(int &i : a)
            cin >> i;
        for(int &i : b)
            cin >> i;
        for(int i = m - 1; i >= 0; i--)
        {
            int j, last = a.back();
            for(j = n - 2; j >= 0 && a[j] > b[i]; j--)
                a[j + 1] = a[j];

            if(j != n - 2 || last > b[i])
            {
                a[j + 1] = b[i];
                b[i] = last;
            }
        }
        for(int x : a)
            cout << x << " ";
        for(int x : b)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}