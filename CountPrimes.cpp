/**
Count Primes Total Accepted: 1946 Total Submissions: 12035 My Submissions 

Description:

Count the number of prime numbers less than a non-negative number, n

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Author: haoya
Time:	2015/4/28 15:26
*/
//埃拉托斯特尼筛法 http://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95
int countPrimes(int n){
    int cnt=0;
    bool *num = (bool*)malloc(sizeof(bool)*n);
    for(int i=0;i<n;i++){
        num[i] = true;
    }
    int i=2;
    while(i*i<=n) {
        for (int c = 2, idx = c * i; idx < n; ++c, idx = i * c)
            num[idx] = false;
        do {
            i++;
        } while (i * i <= n && num[i] == false);
    }
    for(int i=2;i<n;i++)
        if(num[i])
            cnt++;
    return cnt;
}