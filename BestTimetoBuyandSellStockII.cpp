/**
Best Time to Buy and Sell Stock II Total Accepted: 30905 Total Submissions: 83959 My Submissions Question Solution 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Hide Tags Array Greedy


Author: haoya5509
Time: 12:07AM 2014/12/5
*/

int maxProfit(vector<int> &prices) {
	int res=0;        
	int index1=0,index2=1;
	while(index1<prices.size()){
		while(index1+1<prices.size()&&prices[index1]>=prices[index1+1])
			index1++;
		index2=index1+1;
		while(index2+1<prices.size()&&prices[index2]<=prices[index2+1])
			index2++;
		if(index2<prices.size())
			res+=prices[index2]-prices[index1];
		index1=index2+1;
	}
	return res;
}