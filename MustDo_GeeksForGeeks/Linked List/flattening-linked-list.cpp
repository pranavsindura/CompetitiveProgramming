/*
	FLATTEN A LINKED LIST and Sort it
	Individual Lists are Sorted
*/
/*
	Approach 1 - Make new List and Bubble Sort
	Approach 2 - Insertion Sort
	Approach 3 - Merge Sort Like Merging two sorted Lists
*/

// Approach 2
Node *insert_sort(Node *head, Node *ins)
{
    // cout<<ins->data<<" ";
    if(head == NULL)
    {
        // cout<<"head is null\n";
        Node *ptr = new Node(ins->data);
        head = ptr;
        return head;
    }
    else if(ins->data < head->data)
    {
        //insert at beginning
        Node *ptr = new Node(ins->data);
        ptr->bottom = head;
        return ptr;
    }
    else
    {
        //find pos
        Node *prev = head, *curr = head->bottom;
        while(curr && curr->data <= ins->data)
        {
            prev = prev->bottom, curr = curr->bottom;
        }
        if(curr)
        {
            //insert at pos
            Node *ptr = new Node(ins->data);
            ptr->bottom = curr;
            prev->bottom = ptr;
        }
        else
        {
            //insert at end
            Node *ptr = new Node(ins->data);
            prev->bottom = ptr;
        }
        return head;
    }
}

Node *flatten(Node *root)
{
    Node *head = NULL, *temp = root;
    while(temp)
    {
        Node *bot = temp;
        while(bot)
        {
            head = insert_sort(head, bot);
            bot = bot->bottom;
        }
        temp = temp->next;
    }
    return head;
}

// Approach 3
Node *merge(Node *flattened_list, Node *list)
{
    Node *p1 = flattened_list, *p2 = list;
    Node *head = NULL, *temp = NULL;
    while(p1 && p2)
    {
        if(p1->data <= p2->data)
        {
            //Add p1 to list
            Node *p = new Node(p1->data);
            if(temp)
            {
                temp->bottom = p;
                temp = temp->bottom;
            }
            else
                head = p, temp = p;
            p1 = p1->bottom;
        }
        else
        {
            //Add p2 to list
            Node *p = new Node(p2->data);
            if(temp)
            {
                temp->bottom = p;
                temp = temp->bottom;
            }
            else
                head = p, temp = p;
            p2 = p2->bottom;
        }
    }
    while(p1)
    {
        //Add p1 to list
        Node *p = new Node(p1->data);
        if(temp)
        {
            temp->bottom = p;
            temp = temp->bottom;
        }
        else
            head = p, temp = p;
        p1 = p1->bottom;
    }

    while(p2)
    {
        //Add p2 to list
        Node *p = new Node(p2->data);
        if(temp)
        {
            temp->bottom = p;
            temp = temp->bottom;
        }
        else
            head = p, temp = p;
        p2 = p2->bottom;
    }
    return head;
}

Node *flatten(Node *root)
{
    // Your code here
    Node *head = NULL, *temp = root;
    while(temp)
    {
        head = merge(head, temp);
        temp = temp->next;
    }
    return head;
}