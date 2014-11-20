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
#include<utility>
#include<unordered_set>
#include<queue>
#include<map>
using namespace std;
int ladderLength(string start, string end, unordered_set<string> &dict) {
	map<string,int> flag;
	flag[start]=1;
	queue<string> bfs;
	bfs.push(start);
	while(!bfs.empty()){
		string str=bfs.front();
		bfs.pop();
		for(int i=0;i<str.size();i++){
			string tmp=str;
			for(char j='a';j<='z';j++){
				tmp[i]=j;
				if(tmp==end){
					return flag[str]+1;
				}
				if(dict.count(tmp)>=1&&flag.count(tmp)==0){
					bfs.push(tmp);
					flag[tmp]=flag[str]+1;
				}
			}
		}
	}
	return 0;
}
int main(){
	string begin("hot");
	string end("dog");
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dog");
	for(unordered_set<string>::iterator iter=dict.begin();iter!=dict.end();iter++){
		cout<<*iter<<endl;
	}
	//unordered_set<string>::iterator iter=dict.find("hot");
	//cout<<iter-dict.begin()<<endl;
	cout << ladderLength(begin,end,dict) << endl;
	return 0;
}