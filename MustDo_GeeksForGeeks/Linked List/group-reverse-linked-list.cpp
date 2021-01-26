/*
	Reverse Linked List in Groups of K
*/
/*
	Approach 1 -
	Break Linked List into groups of K
	Reverse Independently
	Merge them
*/
#define Node struct node
Node *reverseList(Node *head)
{
	//Reverse a Linked List
    Node *prev = NULL, *curr = head, *next;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *reverse (Node *head, int k)
{
    // Complete this method
    int len = 0;
    Node *temp = head, *prev_head = head;

    //Break Linked List into groups of k, store heads in array.
    vector<Node *> head_arr;
    while(temp != NULL)
    {
        len++;
        if(len % k == 0)
        {
            head_arr.push_back(prev_head);
            Node *curr = temp;
            temp = temp->next;
            curr->next = NULL;
            prev_head = temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    if(len % k)
        head_arr.push_back(prev_head);


    // Independently Reverse each k sized Linked List
    vector<Node *> new_head_arr;
    for(int i = 0; i < (int)head_arr.size(); i++)
    {
        new_head_arr.push_back(reverseList(head_arr[i]));
    }

    // Merge k sized Linked Lists
    for(int i = 0; i < ((int)new_head_arr.size()) - 1; i++)
    {
        temp = new_head_arr[i];
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_head_arr[i + 1];
    }

    
    return new_head_arr[0];
}