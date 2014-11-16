/**
 *Sum Root to Leaf Numbers Total Accepted: 27210 Total Submissions: 91201 My Submissions Question Solution 
 Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

 An example is the root-to-leaf path 1->2->3 which represents the number 123.

 Find the total sum of all root-to-leaf numbers.

 For example,

     1
	    / \
		  2   3
		  The root-to-leaf path 1->2 represents the number 12.
		  The root-to-leaf path 1->3 represents the number 13.

		  Return the sum = 12 + 13 = 25.

Author: haoya5509
Time: 7:29PM 2014/11/16
 * */
void dfs(TreeNode *p,int tmp,int &res){
	if(p->left==NULL&&p->right==NULL){
		res+=tmp;
		return;
	}
	if(p->left)
		dfs(p->left,tmp*10+p->left->val,res);
	if(p->right)
		dfs(p->right,tmp*10+p->right->val,res);
}
int sumNumbers(TreeNode *root) {
	if(root==NULL) return 0;
	int res=0;
	int tmp=0;
	dfs(root,root->val,res);
	return res;
}	
