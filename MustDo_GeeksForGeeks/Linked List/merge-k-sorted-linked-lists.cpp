/*
	Merge K Sorted Linked Lists
*/

/*
	Approach 1 - Merge Sort like merging O(n*k)
*/
Node *mergeKLists(Node *arr[], int N)
{
    Node *head = NULL;
    Node *ptr = NULL;
    bool done = false;
    while(!done)
    {
        int pos = -1;
        int val = INT_MAX;
        done = true;
        for(int i = 0; i < N; i++)
        {
            if(arr[i] && arr[i]->data < val)
            {
                val = arr[i]->data;
                pos = i;
                done = false;
            }
        }

        if(!done)
        {
            Node *temp = new Node(val);
            if(head == NULL)
            {
                ptr = temp;
                head = ptr;
            }
            else
            {
                ptr->next = temp;
                ptr = temp;
            }
            arr[pos] = arr[pos]->next;
        }

    }
    return head;
}
