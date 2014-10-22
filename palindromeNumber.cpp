#include<iostream>
#include<stdlib.h>
#include<string>
#include<cmath>
using namespace std;
class Solution{
public:
    bool isPalindrome(int x){
        int tmp = x;
        int cnt = tmp==0?1:0;
        while(tmp){
            tmp/=10;
            cnt++;
        }
        if(x<0) return false;
        //if(x>-10 && x<10) return true;
        if(x%((int)pow(10,(cnt+1)/2)) == reverse(x/(int)pow(10,cnt/2)))
           return true;
        return false;
    }
    int reverse(int x){
        int x_reverse = 0;
        int fac = 10;
        while(x){
            x_reverse *= fac;
            x_reverse += x%fac;
            x/=fac;
        }
        return x_reverse;
    }
};
int main(){
    Solution solution;
    cout << solution.isPalindrome(1) <<endl;
    int a = 10522545459;
    cout << a << endl;
    return 0;
}