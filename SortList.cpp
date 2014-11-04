/**
Sort List Total Accepted: 26240 Total Submissions: 127301 My Submissions Question Solution 
Sort a linked list in O(n log n) time using constant space complexity.

Hide Tags Linked List Sort

Auther: haoya5509
Time: 10:57pm 2014/11/4
*/

//归并排序，O(nlogn),space O(1)
#include<iostream>
using namespace std;
ListNode *mergeSort(ListNode *p,int len){
	if(len==1) return p;
	int mid=len/2,mbak=mid;
	ListNode *q=p;
	while(mbak){
		q=q->next;
		mbak--;
	}
	ListNode *a=mergeSort(p,mid);
	ListNode *b=mergeSort(q,len-mid);
	ListNode res(0),*begin=&res; //哨位
	int c=0,d=0;
	while(c<mid||d<len-mid){
		if(c>=mid || (d<len-mid&&a->val>b->val)){
			begin->next=b;
			b=b->next;
			begin=begin->next;
			d++;
		}else{
			c++;
			begin->next=a;
			a=a->next;
			begin=begin->next;
		}
	}
	begin->next=NULL;
	return res.next;
}
ListNode *sortList(ListNode *head) {
	if(!head) return NULL;
	int len=0;
	ListNode *p=head;
	while(p){
		len++;
		p=p->next;
	}
	return mergeSort(head,len);
}