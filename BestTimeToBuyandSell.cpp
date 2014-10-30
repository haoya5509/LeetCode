/**
 *Best Time to Buy and Sell Stock Total Accepted: 28146 Total Submissions: 90178 My Submissions Question Solution 
 Say you have an array for which the ith element is the price of a given stock on day i.

 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Author: haoya5509
Time: 12:32AM 2014/10/31
 * */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxProfit(vector<int> &prices){
    if(prices.size()<2) return 0;
	int maxprofit = prices[1]-prices[0]>0?prices[1]-prices[0]:0;
	int minValue = min(prices[1],prices[0]);
	for(size_t i=2;i<prices.size();i++){
		//dp 最优子结构； minValue预存，时间复杂度O(n)
		maxprofit = max(maxprofit,prices[i]-minValue);
		maxprofit = maxprofit > 0? maxprofit:0;
		if(prices[i] < minValue) minValue = prices[i];
	}
	return maxprofit;
}
int main(){
	int a[] = {3,2};
	vector<int> data(a,a+2);
	cout << maxProfit(data) << endl;
	return 0;
}
