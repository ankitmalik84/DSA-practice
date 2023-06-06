// ==================================================== CODE INFINITY ===============================================================

// Predecessor and Successor
// MediumAccuracy: 47.36%Submissions: 74K+Points: 4
// Getting a High Paying Job Now Easier Than Today's Problem! Apply For Mega Job-A-Thon

// There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

// Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor.

// Example 1:

// Input:
//         10
//       /   \
//      2    11
//    /  \ 
//   1    5
//       /  \
//      3    6
//       \
//        4
// key = 8
// Output:
// 6 10
// Explanation:
// In the given BST the inorder predecessor of 8 is 6 and inorder successor of 8 is 10.
// Example 2:

// Input:
//       8
//     /   \
//    1     9
//     \     \
//      4    10
//     /
//    3
// key = 11
// Output:
// 10 -1
// Explanation:
// In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.

// =======================APPROACH===================>>>>>>>>>>

// 1. We start from the root of the BST and initialize two pointers, pre and suc, as NULL. These pointers will eventually store the predecessor and successor nodes, respectively.

// 2. We traverse down the tree, comparing the given key with the key of the current node.

// 3. If the current node's key matches the given key, we have found the node with the target key in the tree. In this case, we update the predecessor and successor nodes:

// 4. To find the predecessor, we move to the left subtree of the current node (if it exists) and find the maximum value in that subtree. This maximum value will be the predecessor.
// 5. To find the successor, we move to the right subtree of the current node (if it exists) and find the minimum value in that subtree. This minimum value will be the successor.
// 6. If the current node's key is greater than the given key, it means the target key lies in the left subtree. So, we update the successor pointer to the current node and move to the left child of the current node.

// 7. If the current node's key is smaller than the given key, it means the target key lies in the right subtree. So, we update the predecessor pointer to the current node and move to the right child of the current node.

// 8. We repeat steps 3-5 until we find the node with the given key or reach a NULL node.

// 9. After the traversal, we have updated the pre and suc pointers with the predecessor and successor nodes, respectively, if they exist. If the target key is not present or there is no predecessor/successor, the pointers will remain NULL.

// ================= CODE ==================>>>>>>>

// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

// } Driver Code Ends

/* BST Node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x){
        key = x;
        left = NULL;
        right = NULL;
    }
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        Node *curr = root;
        while (curr)
        {
            if (curr->key == key)
            {
                // If the key is found in the tree
                // Inorder predecessor is the maximum value in the left subtree
                if (curr->left)
                {
                    pre = curr->left;
                    while (pre->right)
                        pre = pre->right;
                }

                // Inorder successor is the minimum value in the right subtree
                if (curr->right)
                {
                    suc = curr->right;
                    while (suc->left)
                        suc = suc->left;
                }

                return;
            }
            else if (curr->key > key)
            {
                // If the key is smaller than the current node, move to the left subtree
                suc = curr;
                curr = curr->left;
            }
            else
            {
                // If the key is greater than the current node, move to the right subtree
                pre = curr;
                curr = curr->right;
            }
        }
    }
};

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
// Driver program to test above functions
int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre = NULL, *succ = NULL;
        Solution ob;
        ob.findPreSuc(root, pre, succ, k);
        (pre != NULL) ? cout << pre->key : cout << -1;
        cout << " ";
        (succ != NULL) ? cout << succ->key : cout << -1;
        cout << endl;
        // inOrderTraversal(root);
    }
    return 0;
}
