

#include <bits/stdc++.h>
/*********************************************************

    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };

************************************************************/

Node *
reverseDLLInGroups(Node *head, int k)
{
    Node *current = head;
    Node *next = nullptr;
    Node *prev = nullptr;
    int count = 0;
    // cout<<head->data;
    // Count the number of nodes in the current group
    while (current != nullptr && count < k)
    {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
        count++;
    }
    // cout<<head->data;
    // Recursively reverse the next group and connect with the current group
    if (next != nullptr)
    {
        head->next = reverseDLLInGroups(next, k);
        head->next->prev = head;
    }
    // cout<<head->data;

    return prev; // New head of the reversed group
}
