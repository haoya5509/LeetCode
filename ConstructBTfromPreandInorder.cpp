/**
Construct Binary Tree from Preorder and Inorder Traversal Total Accepted: 20012 Total Submissions: 75615 My Submissions Question Solution 
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Author: haoya5509
Time: 12:00AM 2014/11/17
*/
TreeNode *buildInner(vector<int> &pre,vector<int> &in,int l,int r,int &b){
	if(b==pre.size())
		return NULL;
	if(l==r)
		return NULL;
	if(l+1==r)
		return new TreeNode(pre[b++]);
	TreeNode *root=new TreeNode(pre[b++]);
	int i;
	for(i=l;i<r;i++)
		if(in[i]==pre[b-1])
			break;
	root->left=buildInner(pre,in,l,i,b);
	root->right=buildInner(pre,in,i+1,r,b);
	return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {  
	int b=0;      
	return buildInner(preorder,inorder,0,preorder.size(),b);
}