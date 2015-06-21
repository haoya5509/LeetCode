public:
    void swap(ListNode **n1,ListNode **n2){
    ListNode *tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void sink(vector<ListNode *> &heap,int index,int range){
    while(index < range){
        int lindex = 2*index+1;
        int rindex = 2*index+2;
        int min,next;
        if(lindex < range){
            min = heap[lindex]->val;
            next = lindex;
        }else
            return;
        if(rindex < range){
            if(heap[rindex]->val < min){
                min = heap[rindex]->val;
                next = rindex;
            }
        }
        if(heap[index]->val > min){
            swap(&heap[index],&heap[next]);
            index = next;
        } else
            return;
    }
}

void buildHeap(vector<ListNode *> &heap){
    int min,index;
    for(size_t i=heap.size()-1;i>0;i--){
        min = heap[i]->val;
        index = i;
        if(i%2==0 && heap[i-1]->val < min) {
            min = heap[i - 1]->val;
            index = i-1;
        }
        if((i-1)/2>=0 && heap[(i-1)/2]->val > min){
            swap(&heap[index],&heap[(i-1)/2]);
            sink(heap,index,heap.size());
        }
    }
}
ListNode *mergeKLists(vector<ListNode *> &lists){
    for(vector<ListNode *>::iterator it=lists.begin();it!=lists.end();){
        if(*it==NULL){
            it = lists.erase(it);
        }else{
            it++;
        }
    }if(lists.size()==0) return NULL;
    ListNode res(0);
    vector<ListNode *> minHeap(lists.begin(),lists.end());
    buildHeap(minHeap);
    res.next = minHeap[0];
    ListNode *head = res.next;
    minHeap[0] = minHeap[0]->next;
    if(minHeap[0]==NULL){
            swap(&minHeap[0],&minHeap[minHeap.size()-1]);
            minHeap.erase(minHeap.begin()+minHeap.size()-1);
            sink(minHeap,0,minHeap.size());
        }
    while(minHeap.size()>0){
        if(minHeap[0]==NULL){
           swap(&minHeap[0],&minHeap[minHeap.size()-1]);
            minHeap.erase(minHeap.begin()+minHeap.size()-1);
            sink(minHeap,0,minHeap.size());
        }else{
            sink(minHeap,0,minHeap.size());
            head->next = minHeap[0];
            head = head->next;
            minHeap[0] = minHeap[0]->next;
        }
    }
    return res.next;
}