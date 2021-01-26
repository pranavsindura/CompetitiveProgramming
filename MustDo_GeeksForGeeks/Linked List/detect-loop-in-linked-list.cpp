/*
	Detect Loop in Linked List
*/

/*
	Approach 1 - Use Hashing to see if visited before O(nlogn) time O(n) space
	Approach 2 - Floyd's Cycle Detection
		Use of Slow and Fast pointer
		If they conincide at some point in the future then there is a cycle O(n) time O(1) space
*/

// Approach 1
#include<map>
int detectloop(Node *head)
{

    // your code here
    map<Node *, bool> vis;
    bool loop = false;
    Node *temp = head;
    while(temp != NULL)
    {
        if(vis[temp])
        {
            loop = true;
            break;
        }
        vis[temp] = true;
        temp = temp->next;
    }
    return loop;
}

// Approach 2
int detectloop(Node *head)
{
    bool loop = false;
    Node *slow = head, *fast = head;
    while(slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            loop = true;
            break;
        }
    }
    return loop;
}