#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/

void insert(Node * ( & head), int n, int pos, int val) {
    // Write your code here
    if (pos < 0) {
        return;
    }

    Node* newNode = new Node(val);

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        delete newNode;
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}