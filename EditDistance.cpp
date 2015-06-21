#include<iostream>
#include<string>
#include<vector>
using namespace std;
int minDistance(string word1, string word2){
	vector<vector<int>> minDistance(word1.size(), vector<int>(word2.size(), 0));
	for (int i = 0; i < minDistance.size(); ++i){
		for (int j = 0; j < minDistance[0].size(); ++j){
			if (i == 0)
				minDistance[i][j] = word2.size();
			else if (j == 0)
				minDistance[i][j] = word1.size();
		}
	}
	for (int i = 0; i < minDistance.size(); ++i){
		for (int j = 0; j < minDistance[0].size(); ++j){
			int cost = (word1[i] == word2[j]) ? 0 : 1;
			minDistance[i][j] = min(min(minDistance[i - 1][j], minDistance[i][j - 1]), minDistance[i - 1][j - 1] + cost);
		}
	}
	return minDistance[word1.size() - 1][word2.size() - 1];
}
int main(){

}