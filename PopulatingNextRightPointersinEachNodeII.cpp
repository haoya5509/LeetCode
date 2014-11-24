/**
Populating Next Right Pointers in Each Node II Total Accepted: 23420 Total Submissions: 75863 My Submissions Question Solution
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

Author: haoya5509
Time: 2014/11/24 22:26PM
*/
void connect(TreeLinkNode *root) {
    if(root==NULL) return;
    TreeLinkNode *p=root->left,*q=root->right;
    while(p&&q){
        p->next = q;
        p=findRight()
        q=q->left?q->left:q->right;
    }
    connect(root->left);
    connect(root->right);
}
