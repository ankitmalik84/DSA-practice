// ==================================================== CODE INFINITY ===============================================================

// Find the Closest Element in BST
// MediumAccuracy: 47.51%Submissions: 62K+Points: 4
// Getting a High Paying Job Now Easier Than Today's Problem! Apply For Mega Job-A-Thon

// Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

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
// K = 13
// Output:
// 2
// Explanation: K=13. The node that has
// value nearest to K is 11. so the answer
// is 2
// Example 2:

// Input:
//       8
//     /   \
//    1     9
//     \     \
//      4    10
//     /
//    3
// K = 9
// Output:
// 0
// Explanation: K=9. The node that has
// value nearest to K is 9. so the answer
// is 0.

// =======================APPROACH===================>>>>>>>>>>

// 1. Inside the Solution class, there is a public variable called distance, initially set to a very large value (100000). This variable will store the minimum absolute difference found during the traversal of the tree.

// 2. The code defines a function called inOrderTraverse, which performs an inorder traversal of the binary tree. In inorder traversal, we visit the left subtree first, then the current node, and finally the right subtree.

// 3. The inOrderTraverse function takes two parameters: a pointer to the current node (root) and the given value k.

// 4. Inside the inOrderTraverse function, the first check is to see if the current node is not NULL (indicating it's a valid node). If the node is valid, the following steps are executed:

// 5. The function calls itself recursively, passing the left child of the current node and the value k. This step is responsible for traversing the left subtree.

// 6. The function compares the current node's data (root->data) with the given value k and calculates the absolute difference using the abs function. The minimum of this absolute difference and the current minimum distance (distance) is then stored in the distance variable.

// 7. The function calls itself recursively, passing the right child of the current node and the value k. This step is responsible for traversing the right subtree.

// 8. The code also defines a function called minDiff, which calculates the minimum absolute difference between the given value k and any node's data in the binary tree.

// 9. The minDiff function takes two parameters: a pointer to the root of the binary tree and the given value k.

// 10. Inside the minDiff function, the first check is to see if the root node is not NULL. If the root is valid, it calls the inOrderTraverse function, passing the root node and the value k. This step initiates the inorder traversal of the tree.

// Finally, the minDiff function returns the minimum distance (distance) calculated during the traversal.

// ================= CODE ==================>>>>>>>

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

/*
Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    int distance = 100000; // the answer to our problem

    // using inorder traversal to get the data of each node of tree

    // Also taking the minimum of the above distance and absolute distance between current node data and given value k.
    void inOrderTraverse(Node *root, int k)
    {
        if (root != NULL)
        {
            inOrderTraverse(root->left, k);
            distance = min(distance, abs(root->data - k));
            inOrderTraverse(root->right, k);
        }
    }
    int minDiff(Node *root, int k)
    {
        if (root != NULL)
        {
            inOrderTraverse(root, k);
        }
        return distance;
    }
};

// Function to Build Tree
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
        Node *root1 = buildTree(s);

        getline(cin, s);
        int k = stoi(s);

        Solution ob;
        cout << ob.minDiff(root1, k);
        cout << endl;
    }
    return 0;
}
