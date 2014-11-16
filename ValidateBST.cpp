/**
Validate Binary Search Tree Total Accepted: 27670 Total Submissions: 107828 My Submissions Question Solution 
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Author: haoya5509
Time: 7:11PM 2014/11/16
*/
bool isLessThan(TreeNode *p,int val){
	if(p==NULL) return true;
	if(p->val>=val)
		return false;
	return isLessThan(p->left,val) && isLessThan(p->right,val);
}
bool isGreatThan(TreeNode *p,int val){
	if(p==NULL) return true;
	if(p->val<=val)
		return false;
	return isGreatThan(p->left,val) && isGreatThan(p->right,val);
} 
bool isValidBST(TreeNode *root) {
	if(root==NULL) return true;
	bool flag=isLessThan(root->left,root->val) && isGreatThan(root->right,root->val);
	if(flag)
		return isValidBST(root->left) && isValidBST(root->right);
	else
	    return false;
}