/*
	Merge Two Sorted Linked List
*/

/*
	Approach 1 - Insertion Sort one List into Another
	Approach 2 - Merge Sort like Merging
	Approach 3 - Recursive Merging
*/
// Approach 2
Node *sortedMerge(Node *head1,   Node *head2)
{
    Node *p1 = head1, *p2 = head2;
    Node *head = NULL, *temp = NULL;
    while(p1 && p2)
    {
        if(p1->data <= p2->data)
        {
            //Add p1 to list
            Node *p = new Node(p1->data);
            if(temp)
            {
                temp->next = p;
                temp = temp->next;
            }
            else
                head = p, temp = p;
            p1 = p1->next;
        }
        else
        {
            //Add p2 to list
            Node *p = new Node(p2->data);
            if(temp)
            {
                temp->next = p;
                temp = temp->next;
            }
            else
                head = p, temp = p;
            p2 = p2->next;
        }
    }
    while(p1)
    {
        //Add p1 to list
        Node *p = new Node(p1->data);
        if(temp)
        {
            temp->next = p;
            temp = temp->next;
        }
        else
            head = p, temp = p;
        p1 = p1->next;
    }

    while(p2)
    {
        //Add p2 to list
        Node *p = new Node(p2->data);
        if(temp)
        {
            temp->next = p;
            temp = temp->next;
        }
        else
            head = p, temp = p;
        p2 = p2->next;
    }
    return head;
}

// Approach 3
Node *sortedMerge(Node *head1,   Node *head2)
{
    if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    Node *res = NULL;
    if(head1->data <= head2->data)
    {
        res = head1;
        res->next = sortedMerge(head1->next, head2);
    }
    else
    {
        res = head2;
        res->next = sortedMerge(head1, head2->next);
    }
    return res;
}