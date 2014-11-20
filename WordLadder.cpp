/**
Word Ladder Total Accepted: 23521 Total Submissions: 127679 My Submissions Question Solution 
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

Author: haoya5509
Time: 11:36PM 2014/11/17
*/

#include<iostream>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;	
bool isOnediff(string tar,string dat){
	int k=0;
	for(int i=0;i<tar.size();i++){
		if(tar[i]!=dat[i])
			k++;
	}
	if(k==1) return true;
	return false;
}
int ladderLength(string start, string end, unordered_set<string> &dict) {
	queue<string> qs;
	queue<int> len;
	qs.push(start);
	len.push(1);
	while(!qs.empty()){
		string str=qs.front();
		int tmp=len.front();
		cout<<str<<".."<<tmp<<endl;
		if(isOnediff(str,end))
			return tmp+1;
		qs.pop();
		len.pop();
		//for(int i=0;i<dict.size();i++){
		for(unordered_set<string>::iterator iter=dict.begin();iter!=dict.end();iter++){
			if(!isOnediff(*iter,str)){
				cout<<*iter<<"~~"<<endl;
				continue;
			}
			qs.push(*iter);
			len.push(tmp+1);
			cout<<"inner:"<<*iter<<"..."<<tmp+1<<endl;
			dict.erase(iter);
		}
	}
	return 0;
}
int main(){
	string begin("hot");
	string end("dog");
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("cog");
	dict.insert("dog");
	dict.insert("tot");
	dict.insert("hog");
	dict.insert("hop");
	dict.insert("pot");
	dict.insert("dot");
	for(unordered_set<string>::iterator iter=dict.begin();iter!=dict.end();iter++){
		cout<<*iter<<endl;
	}
	//unordered_set<string>::iterator iter=dict.find("hot");
	//cout<<iter-dict.begin()<<endl;
	cout << ladderLength(begin,end,dict) << endl;
	return 0;
}