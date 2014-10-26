/**
Valid Sudoku Total Accepted: 16650 Total Submissions: 60080 My Submissions Question Solution 
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Author: haoya5509  
Time 11:34PM 2014/10/26 
*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
bool isValidSudoku(vector<vector<char> > &board) {
    bool flag[10] = {0};
    for(int i=0;i<3;i++){
        for(int m=0;m<3;m++){
            memset(flag,0,sizeof(flag));
            for(int j=0;j<3;j++){
                for(int n=0;n<3;n++){
                    if(board[3*i+j][3*m+n] != '.'){
                        int index = board[3*i+j][3*m+n]-'0';
                        if(flag[index])
                            return false;
                        flag[index] = 1;
                    }
                }
            }
        }
    }
    for(int i=0;i<9;i++){
        memset(flag,0,sizeof(flag));
        for(int j=0;j<9;j++){
            if(board[i][j] != '.'){
                int index = board[i][j]-'0';
                if(flag[index])
                    return false;
                flag[index] = 1;
            }
        }
    }
    for(int i=0;i<9;i++){
        memset(flag,0,sizeof(flag));
        for(int j=0;j<9;j++){
            if(board[j][i] != '.'){
                int index = board[j][i]-'0';
                if(flag[index])
                    return false;
                flag[index] = 1;
            }
        }
    }
    
    return true;
}
int main(){
    vector<vector<char> > chVec = {{'.','.','5','.','.','.','.','.','6'},
        {'.','.','.','.','1','4','.','.','.'},{'.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','9','2','.','.'},{'5','.','.','.','.','2','.','.','.'},{'.','.','.','.','.','.','.','3','.'},{'.','.','.','5','4','.','.','.','.'},{'3','.','.','.','.','.','4','2','.'},{'.','.','.','2','7','.','6','.','.'}
    };
    cout << isValidSudoku(chVec);
    return 0;
}