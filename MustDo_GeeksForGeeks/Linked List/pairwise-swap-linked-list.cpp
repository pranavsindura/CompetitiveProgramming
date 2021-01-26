/*
	Pairwise swap elements of Linked List
*/

/*
	Approach 1 - Swap Data, Costly when data is a lot
	Approach 2 - Swap nodes/links, Cheaper
*/

// Approach 1
Node *pairWiseSwap(struct Node *head)
{
    Node *p1 = head, *p2 = head->next;
    while(p1 && p2)
    {
        swap(p1->data, p2->data);
        p2 = p2->next;
        p1 = p2;
        if(p2)
            p2 = p2->next;
    }
    return head;
}

// Approach 2
Node *pairWiseSwap(struct Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node *new_head = head->next;
    Node *remaining_list = pairWiseSwap(head->next->next);
    head->next = remaining_list;
    new_head->next = head;
    return new_head;
}