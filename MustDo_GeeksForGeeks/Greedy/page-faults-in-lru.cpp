/*
	Page Faults in LRU

	In operating systems that use paging for memory management,
	page replacement algorithm are needed to decide which page
	needs to be replaced when the new page comes in. Whenever a
	new page is referred and is not present in memory, the page fault
	occurs and Operating System replaces one of the existing pages with a
	newly needed page. Given a sequence of pages and memory capacity,
	your task is to find the number of page faults using
	Least Recently Used (LRU) Algorithm.
*/

/*
	Approach 1 - Similar to LRU Cache (STACKS AND QUEUES)
		We can have a List of the Pages and vector which tells us the position of the Pages
		Every time a page is requested we handle by removing its occurance and moving it to the front
		Adding and removing also works similar to LRU Cache
		O(1) insertion and deletion

	Approach 2 - Noticing that the constraints are small, we can hold just a array which tells us the usage
		times of each page, And we while removing we can simply Loop and find the LRU item
		O(n^2)
*/

void cp()
{
    int n, cap;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    cin >> cap;

    int timestamp = 1;
    vector<int> usage(1001, 0);
    int curr_sz = 0;
    int faults = 0;
    for(int i = 0; i < n; i++)
    {
        int page = arr[i];
        if(usage[page])
        {
            // already present, update timestamp
            usage[page] = timestamp++;
        }
        else
        {
            // not present, check if we can insert
            if(curr_sz < cap)
            {
                // increase size
                curr_sz++;
            }
            else
            {
                // have to remove something
                // Find smallest usage time and remove it
                int pos = 0;
                int mn = INT_MAX;
                for(int j = 0; j <= 1000; j++)
                {
                    if(usage[j] > 0 && usage[j] < mn)
                        mn = usage[j], pos = j;
                }
                usage[pos] = 0;
            }
            //update timestamp
            usage[page] = timestamp++;
            //increase faults
            faults++;
        }
    }
    cout << faults << endl;
}
