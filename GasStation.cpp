/**
Gas Station Total Accepted: 26488 Total Submissions: 102403 My Submissions Question Solution 
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

Author: haoya5509
Time: 10:38PM 2014/12/4
*/
#include<iostream>
#include<vector>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	vector<int> diff;
	for(int i=0;i<gas.size();i++){
		diff.push_back(gas[i]-cost[i]);
	}
	int len=diff.size();
	for(int i=0;i<len;i++){
		if(diff[i]<0) continue;
		int sum=diff[i];
		int flag=1;
		for(int j=1;j<len;j++){
			int k=i+j;
			k=k>=len?(k%len):k;
			sum+=diff[k];
			if(sum<0){
				flag=0;
				break;
			}
		}
		if(flag==1&&sum>=0)
			return i;
	}
	return -1;
}
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    vector<int> rest;//how much gas rest after arriving at next station.
    int n=gas.size(),excess=0,lack=0,index=0;
    for(int i=0;i<n;i++){
        rest.push_back(gas[i]-cost[i]);
        excess+=rest[i];//the amount redundant gas
        if(excess<0)//when the amount redundant gas less than 0, the car cannot arrive at next station.
        lack+=excess,excess=0,index=i+1;//The start point need to be renewed.Also amount of lacking gas need to added.
    }
    if(lack+excess>=0)return index;//If the car started from the last possible point, the excessing gas should more than amount of lacking gas
    else return -1;
}
int main(){
	int agas[]={2,4};
	vector<int> gas(agas,agas+2);
	int acost[]={3,4};
	vector<int> cost(acost,acost+2);
	cout<<canCompleteCircuit(gas,cost)<<endl;
	return 0;
}