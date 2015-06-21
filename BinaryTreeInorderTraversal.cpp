/**
<<<<<<< HEAD
 * Binary Tree Inorder Traversal Total Accepted: 58636 Total Submissions: 162241 My Submissions Question Solution 
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *        \
 *             2
 *                 /
 *                    3
 * return [1,3,2].
 * 
 * Author:	haoya
 * Time:	2015/4/2 8:09pm
 * */

struct Node{
	TreeNode *node;
	bool flag;
	Node():flag(false){}
	Node(TreeNode *node,bool flag):node(node),flag(flag){}
};

vector<int> inorderTraversal(TreeNode *root) {
	vector<int> res;
	stack<Node> s;
	if(root == NULL)
		return res;
	Node r(root,false);
	s.push(r);
	while(!s.empty()){
		Node p = s.top();
		s.pop();
		if(p.node->right)
			s.push(Node(p.node->right,false));
		if(p.flag == true || p.node->left == NULL)
			res.push_back(p.node->val);
		if(p.node->left){
			s.push(Node(p.node,true));
			s.push(Node(p.node->left,false));
		}
	}
	return res;
}

void inorderTraversal(TreeNode *root){
	if(root == NULL) return;
	inorderTraversal(root->left);
	cout << root->val << endl;
	inorderTraversal(root->right);
}

=======
Binary Tree Inorder Traversal Total Accepted: 58705 Total Submissions: 162446 My Submissions Question Solution
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

Author: haoya
Time:   2015/4/3 9:21am
*/

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    if(root == NULL) return res;

}
>>>>>>> 79902257ff5cdc1f6fa11f78da7597bf42ccddd8
