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
    queue<pair<TreeLinkNode *,int> > q;
    q.push(make_pair(root,1));
    TreeLinkNode *cur=root;
    int cnt=0;
    while(!q.empty()){
        pair<TreeLinkNode *,int> tmp=q.front();
        q.pop();
        if(tmp.second!=cnt){
          cnt=tmp.second;
          cur->next=NULL;
          cur=tmp.first;
        }else{
          cur->next=tmp.first;
          cur=cur->next;
        }
        if(tmp.first->left){ 
          q.push(make_pair(tmp.first->left,tmp.second+1));
        }
        if(tmp.first->right){ 
          q.push(make_pair(tmp.first->right,tmp.second+1));
        }
    }
}
