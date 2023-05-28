// ==================================================== CODE INFINITY ===============================================================

// Nth node from end of linked list
// EasyAccuracy: 41.18%Submissions: 303K+Points: 2
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

// Example 1:

// Input:
// N = 2
// LinkedList: 1->2->3->4->5->6->7->8->9
// Output: 8
// Explanation: In the first example, there
// are 9 nodes in linked list and we need
// to find 2nd node from end. 2nd node
// from end is 8.
// Example 2:

// Input:
// N = 5
// LinkedList: 10->5->100->5
// Output: -1
// Explanation: In the second example, there
// are 4 nodes in the linked list and we
// need to find 5th from the end. Since 'n'
// is more than the number of nodes in the
// linked list, the output is -1.

// =======================APPROACH===================>>>>>>>>>>
// 1. The function takes two parameters: a pointer to the head of the linked list (Node *head) and an integer value (int n) representing the position from the last node that we want to retrieve.

// 2. It starts by creating a temporary pointer called temp and sets it to the head of the linked list. This pointer will be used to traverse the linked list.

// 3. A variable called count is initialized to 0. This variable will keep track of the number of nodes in the linked list.

// 4. A loop is executed to count the number of nodes in the linked list. The loop continues until the temp pointer reaches the end of the linked list (i.e., temp becomes NULL). Inside the loop, the count is incremented by 1, and the temp pointer is moved to the next node.

// 5. After the loop, there are three possible scenarios:

//         a. If the value of count is less than n, it means there are fewer nodes in the linked list than the requested position n from the last node. In this case, the function returns -1 to indicate an error or an invalid position.

//         b. If the value of count is equal to n, it means the requested position is the first node in the linked list. In this case, the function returns the data value of the head node (head->data).

//         c. If neither of the above conditions is met, it means the requested position is somewhere within the linked list. To find the node, another loop is executed. This loop runs count - n + 1 times.

// 6.Inside the second loop, the head pointer is moved to the next node count - n + 1 times. This effectively positions the head pointer at the node we want to retrieve.

// Finally, after the second loop, the function returns the data value of the node pointed to by the head pointer (head->data).

// .
// ================= CODE ==================>>>>>>>
// .

// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int getNthFromLast(struct Node *head, int n);

/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    int getNthFromLast(Node *head, int n)
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (count < n)
        {
            return -1;
        }
        if (count == n)
        {
            return head->data;
        }
        int iter = count - n + 1;
        while (iter >= 2)
        {
            head = head->next;
            iter--;
        }
        return head->data;
    }
};

int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.getNthFromLast(head, k) << endl;
    }
    return 0;
}