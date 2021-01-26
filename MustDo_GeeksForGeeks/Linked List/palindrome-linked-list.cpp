/*
	Check if Linked List is Palindrome
*/

/*
	Approach 1 - Reverse List and Check O(n) time O(n) space
	Approach 2 - Reverse only second half and check O(n) time O(1) space (IF MODIFICATION IS ALLOWED)
*/
//Approach 1
bool isPalindrome(Node *head)
{
    Node *temp = head;
    Node *rev_head = NULL;
    while(temp)
    {
        Node *p = new Node(temp->data);
        p->next = rev_head;
        rev_head = p;
        temp = temp->next;
    }
    bool equal = true;
    temp = head;
    while(temp && rev_head)
    {
        if(temp->data != rev_head->data)
            equal = false;
        Node *prev = rev_head;
        temp = temp->next, rev_head = rev_head->next;
        delete prev;
    }
    return equal;
}

// Approach 2
bool isPalindrome(Node *head)
{
    Node *temp = head;
    // Calculate Length
    int len = 0;
    while(temp)
        len++, temp = temp->next;
    temp = head;

    int half = (len + 1) / 2;
    int pos = 0;
    // Get to Half
    Node *midnode = NULL;
    while(temp && pos < half)
    {
        midnode = temp;
        temp = temp->next;
        pos++;
    }
    // Reverse second half
    Node *prev = NULL, *curr = temp;
    while(curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    midnode->next = prev;

    // Start checking from head and midnode+1
    Node *left = head, *right = prev;
    bool equal = true;
    while(left && right)
    {
        if(left->data != right->data)
            equal = false;
        left = left->next, right = right->next;
    }
    return equal;
}