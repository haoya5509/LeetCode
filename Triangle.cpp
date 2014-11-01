#include<iostream>
#include<vector>
using namespace std;
int minimumTotal(vector<vector<int> &triangle){
	int minimum = 0;
	int len = triangle[triangle.size()-1].size();
	vector<int> data(len);
	for(size_t i=0;i!=triangle.size();i++){
		for(size_t j=0;j<triangle[i].size();j++){
			minimum = j-1<0 ? data[j] : data[j-1];
			if(i == 0) {
				data[j] = triangle[i][j];
				break;
			}
			data[j] = min(minimum,data[j]) + triangle[i][j];
		}
	}
	return *min_element(data.begin(),data.end());
}
int main(){
	return 0;
}
