/**
Min Stack Total Accepted: 5206 Total Submissions: 33856 My Submissions Question Solution 
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Author: haoya5509
Time: 11:05PM 2014/11/17
*/

class MinStack {
	int myStack[100000];
	int pos;
	int min;
public:
	MinStack(){
		pos=-1;
		min=0;
	}
    void push(int x) {
        myStack[++pos]=x;
        if(pos==0)
        	min=x;
       	if(x<min)
       		min=x;
    }

    void pop() {
        if(pos>=0){
        	--pos;
        	if(pos>=0){
        		min=myStack[0];
        		for(int i=1;i<=pos;i++){
        			if(myStack[i]<min)
        				min=myStack[i];
        		}
        	}
        }
    }

    int top() {
        if(pos>=0)
        	return myStack[pos];
    }

    int getMin() {
        return min;
    }
};