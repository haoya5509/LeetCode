/**
Binary Search Tree Iterator Total Accepted: 1675 Total Submissions: 5800 My Submissions Question Solution 
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Author:	haoya
Time:	11:07PM 2015/1/3
*/		

class BSTIterator {
private:
	stack<TreeNode *> s;
public:
    BSTIterator(TreeNode *root) {
    	TreeNode *cnt=root;
    	while(cnt){
        	s.push(cnt);
    		cnt=cnt->left;
    	}
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(s.empty())
        	return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
    	TreeNode *node=s.top();
    	s.pop();
    	int res=node->val;
    	if(node->right){
    		TreeNode *p=node->right;
    		while(p){
    			s.push(p);
    			p=p->left;
    		}
    	}
        return res;
    }
};