/**
Construct Binary Tree from Inorder and Postorder Traversal Total Accepted: 19085 Total Submissions: 71993 My Submissions Question Solution 
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Author: haoya5509
Time: 12:23AM 2014/11/17
*/
TreeNode *buildInner(vector<int> &in,vector<int> &post,int l,int r,int &e){
	if(e<0)
		return NULL;
	if(l==r)
		return NULL;
	if(l+1==r)
		return new TreeNode(post[e--]);
	TreeNode *root=new TreeNode(post[e--]);
	int i;
	for(i=l;i<r;i++){
		if(post[e+1]==in[i])
			break;
	}
	root->right=buildInner(in,post,i+1,r,e);
	root->left=buildInner(in,post,l,i,e);
	return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int e=inorder.size()-1;
    return buildInner(inorder,postorder,0,inorder.size(),e);
}