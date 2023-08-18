#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void inOrder(BinaryTreeNode* root,vector<int>&arr){
	if(!root) return;

	inOrder(root->left,arr);
	arr.push_back(root->data);
	inOrder(root->right,arr);
}
void helper(BinaryTreeNode* root,vector<int>&arr,int &i){

	if(!root) return;
	if(i==arr.size()) return;

	root->data=arr[i++];
	helper(root->left,arr,i);
	helper(root->right,arr,i);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> arr;
	int i=0;

	inOrder(root,arr);
	helper(root,arr,i);
    
	return root;
}