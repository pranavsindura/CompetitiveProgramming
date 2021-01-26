/*
    KTH SMALLEST ELEMENT IN O(n) time
*/

/*
    Approach 1 - Frequency array O(n)

    Approach 2 - QuickSort with a little change O(n) expected, O(n^2)
                 worst case can be fixed with randomized pivot selection
    we see if pivot index is == k then this element is the kth element
    if it is > k then find it by quick sorting left half
    if it is < k then find it quick sorting right half and decrease k by how many positions we have already have in this  half
*/
//APPROACH 1
int freq[MAXN];
void cp()
{
    clr(freq, 0);
    int n, k;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        freq[a]++;
    }
    cin >> k;
    int count = 0;
    int num = 0;
    while(count < k)
    {
        num++;
        count += freq[num];
    }
    cout << num << endl;
}

//APPROACH 2
int arr[MAXN];

int partition(int l, int r)
{
    int rand_ind = rand() % (r - l + 1) + l;
    swap(arr[rand_ind], arr[r]);
    int pivot = arr[r];
    int j = l;
    for(int i = l; i <= r - 1; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
    swap(arr[j], arr[r]);
    return j;
}

int quick_sort(int l, int r, int k)
{
    if(k > 0 && k <= r - l + 1)
    {
        int p = partition(l, r);
        if(p - l == k - 1)
            return arr[p];
        if(p - l > k - 1)
            return quick_sort(l, p - 1, k);
        else
            return quick_sort(p + 1, r, k - p + l - 1);
    }
    return INT_MAX;
}

void cp()
{

    int n, k;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    int kth = quick_sort(0, n - 1, k);
    cout << kth << endl;
}
