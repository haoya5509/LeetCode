/**
 *Convert Sorted List to Binary Search Tree Total Accepted: 24622 Total Submissions: 89850 My Submissions Question Solution 
 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Author: haoya5509
Time: 7:47PM 2014/11/16
 * */

TreeNode *sortedListToBST(ListNode *head) {
	if(NULL==head)
		return NULL;
	if(NULL==head->next)
		return new TreeNode(head->val);
	ListNode *pMid=findMidPos(head);
	TreeNode *pTreeNode=new TreeNode(pMid->val);
	pTreeNode->left=sortedListToBST(head);
	pTreeNode->right=sortedListToBST(pMid->next);
	return pTreeNode;
}
ListNode *findMidPos(ListNode *p){
	ListNode *p1=p,*p2=p,*res=NULL;
	while(p1!=NULL && p2!=NULL && p2->next!=NULL){
		res=p1;
		p1=p1->next;
		p2=p2->next->next;
	}
	if(res){
		res->next=NULL;
	}
	return p1;
}

