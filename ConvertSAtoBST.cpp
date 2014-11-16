/**
Convert Sorted Array to Binary Search Tree Total Accepted: 26157 Total Submissions: 79146 My Submissions Question Solution 
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Author: haoya5509
Time: 11:49PM 2014/11/16
*/
TreeNode *sortInner(vector<int> &num,int begin,int end){
	if(begin==end)
		return NULL;
	if(begin+1==end)
		return new TreeNode(num[begin]);
	int mid=begin+(end-begin)/2;
	TreeNode *root=new TreeNode(num[mid]);
	root->left=sortInner(num,begin,mid);
	root->right=sortInner(num,mid+1,end);
	return root;
}
TreeNode *sortedArrayToBST(vector<int> &num) {
	return sortInner(num,0,num.size());        
}