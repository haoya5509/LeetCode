#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
ListNode *findLast(ListNode *q){
	if(q==NULL) return NULL;
	ListNode *p=q,*res;
	while(p->next&&p->next->next){
		p=p->next;
	}
	res=p->next;
	p->next=NULL;
	return res;
}
void reorderList(ListNode *head){
	ListNode newHead;
	ListNode *p,*np;
	p = head;
	np = &newHead;
	while(p){
		np->next = p;
		np = np->next;
		p = p->next;
		np->next = findLast(p);
	}
	head = newHead->next;
}
int main(){
	
}
