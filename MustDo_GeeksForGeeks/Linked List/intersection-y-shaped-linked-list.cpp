/*
	Find Intersection point of Y shaped Linked List
*/
/*
	Approach 1 - Use Two Loops O(n*m) time O(1) space
	Approach 2 - Use Hashing O((n+m)logn) time O(n) space
	Approach 3 - Make lengths equal and traverse together O(n+m) time O(1) space
*/
#include<map>
int intersectPoint(Node *head1, Node *head2)
{
    // Approach 1
    Node *p1 = head1;
    while(p1 != NULL)
    {
        Node *p2 = head2;
        while(p2 != NULL)
        {
            if(p1 == p2)
                return p1->data;
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return -1;


    // Approach 2
    map<Node *, bool> vis;
    Node *p1 = head1, *p2 = head2;
    int val = -1;
    while(p1 != NULL)
    {
        vis[p1] = true;
        p1 = p1->next;
    }
    while(p2 != NULL)
    {
        if(vis[p2])
        {
            val = p2->data;
            break;
        }
        p2 = p2->next;
    }
    return val;



    // Approach 3
    int len1 = 0, len2 = 0;
    Node *p1 = head1, *p2 = head2;
    while(p1 != NULL)
        len1++, p1 = p1->next;
    while(p2 != NULL)
        len2++, p2 = p2->next;
    p1 = head1, p2 = head2;
    if(len1 < len2)
        swap(p1, p2), swap(len1, len2);
    while(len1 > len2)
    {
        p1 = p1->next;
        len1--;
    }
    while(p1 != NULL && p2 != NULL)
    {
        if(p1 == p2)
            return p1->data;
        p1 = p1->next;
        p2 = p2->next;
    }
    return -1;
}