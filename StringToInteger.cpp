#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
class Solution{
public:
    bool isSame(int tmp,const string& str){
        for(size_t i=str.length();i>0;i--){
            if(str[i-1]-'0' != tmp%10)
                return false;
            tmp/=10;
        }
        return true;
    }
    int atoi(const char* str){
        int tmp = 0,fac = 10;
        int i = 0;
        int flag = 1,first = 1;
        char ch = '+';
        string ss;
        while(str[i]){
            while(first == 1 && isspace(str[i])){
                i++;
            }
            if(first == 1){
                switch(str[i]){
                    case '+':
                        flag*=-1;
                    case '-':
                        flag*=-1;
                        ch = str[i];
                        i++;
                    default:
                        first++;
                        break;
                }
            }
            if(isdigit(str[i])){
                ss.push_back(str[i]);
                tmp *= fac;
                tmp += str[i]-'0';
            }else{
                if(first == 1)
                    tmp = 0;
                break;
            }
            i++;
        }
        tmp = tmp*flag;
        if(!isSame(abs(tmp),ss)){
            if(ch == '+') return 2147483647;
            if(ch == '-') return -2147483648;
        }
        return tmp;
    }
};
int main(){
    Solution solution;
    cout << solution.atoi("") <<endl;
    int a = 10522545459;
    cout << a << endl;
    return 0;
}