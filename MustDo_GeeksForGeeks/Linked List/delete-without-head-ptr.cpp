/*
	Delete Node without Head pointer ref
*/

/*
	Approach 1 - Copy data from next node into curr node (dirty)
*/
// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{
    // Your code here
    if(node == NULL || node->next == NULL)
        return;
    Node *prev = node, *curr = node->next;
    while(curr->next)
    {
        prev->data = curr->data;
        prev = prev->next;
        curr = curr->next;
    }
    prev->data = curr->data;
    delete curr;
    prev->next = NULL;
}