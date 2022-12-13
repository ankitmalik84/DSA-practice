#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
Node *insertIntoBST(Node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (root->data < d)
    {
        // right part me insert karna hai
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // left part me insert karna h
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}
Node *minVal(Node *root)
{
    Node *temp;
    temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *maxVal(Node *root)
{
    Node *temp;
    temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
Node *deleteFromBST(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        // left part me jao
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        // right partme jao
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

void inOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST " << endl;
    takeInput(root);

    cout << "Printing the BST " << endl;
    levelOrderTraversal(root);

    cout << "Printing inOrder " << endl;
    inOrder(root);
    cout << endl
         << "Printing preOrder " << endl;
    preOrder(root);
    cout << endl
         << "Printing postOrder " << endl;
    postOrder(root);

    cout << endl
         << "Min Value" << endl;
    cout << minVal(root)->data << endl;
    cout << "Max Value" << endl;
    cout << maxVal(root)->data << endl;
    root = deleteFromBST(root, 30);
    cout << "Printing the BST " << endl;
    levelOrderTraversal(root);

    cout << "Printing inOrder " << endl;
    inOrder(root);
    cout << endl
         << "Printing preOrder " << endl;
    preOrder(root);
    cout << endl
         << "Printing postOrder " << endl;
    postOrder(root);

    cout << endl
         << "Min Value" << endl;
    cout << minVal(root)->data << endl;
    cout << "Max Value" << endl;
    return 0;
}