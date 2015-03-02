/**
Restore IP Addresses Total Accepted: 21550 Total Submissions: 104858 My Submissions Question Solution 
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


Author:	haoya
Time:	2014.12.31 12:37
*/
void dfs(string s,int num,vector<string> &res,vector<int> &tmp){
	if(num==4){
		string str;
		for(int i=0;i<tmp.size();i++){
			for(int j=str.size();j<tmp[i];j++){
				str.push_back(s[j]);
			}
		}
		res.push_back(str);
	}else{
		for(int i=tmp[num];i<s.size();i++){
			int cnt = tmp.find_last_of(".");
			if()
		}
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> res;
	vector<int> tmp;
	dfs(s,0,res,tmp);
	return res;	        
}