#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> getNext(const vector<int>& tmp);
    string countAndSay(int n);
};
vector<int> Solution::getNext(const vector<int>& tmp){
    vector<int> res;
    int i=0,cnt=0;
    while(i<tmp.size()){
        int val = tmp[i++];
        cnt++;
        while(i<tmp.size() && val == tmp[i]){
            i++;
            cnt++;
        }
        res.push_back(cnt);
        res.push_back(val);
        cnt=0;
    }
    return res;
}
string Solution::countAndSay(int n){
    vector<int> res;
    res.push_back(1);
    while(n>1){
        res = getNext(res);
        n--;
    }
    string result;
    for(int i=0;i<res.size();i++){
        result.push_back('0'+res[i]);
        //cout<<res[i];
    }
    return result;
}

int main(){
    Solution so;
    cout << so.countAndSay(5) << endl;
    return 0;
}
