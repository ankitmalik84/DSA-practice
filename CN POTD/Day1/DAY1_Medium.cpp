#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
            public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*************************************************************/
Node *addNodes(Node *head, int n, int m)
{
    Node *temp = head;
    while (temp)
    {
        int mCount = 0;
        // preform m skip iteration
        while (temp && mCount != m)
        {
            temp = temp->next;
            mCount++;
        }
        int nCount = 0, currSum = 0;
        // perform n sum operations
        while (temp && nCount != n)
        {
            currSum += temp->data;
            nCount++;
            // handle condition if size of Linked list is small than n
            if (nCount == n || temp->next == NULL)
            {
                // intialize sumnode
                Node *sumNode = new Node(currSum);
                // link next to sumnode
                sumNode->next = temp->next;
                // link previous node to sumnode
                temp->next = sumNode;
                // increase temp
                temp = temp->next;
            }
            temp = temp->next;
        }
    }
    return head;
}