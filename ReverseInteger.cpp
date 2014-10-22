#include<iostream>
using namespace std;
class Solution{
public:
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
    cout << solution.reverse(-2147447412) << endl;
    return 0;
}