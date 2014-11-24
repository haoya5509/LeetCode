/**
Surrounded Regions Total Accepted: 18039 Total Submissions: 127072 My Submissions Question Solution
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Author: haoya5509
Time: 20:23PM 2014/11/24
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<char> > &board,int x,int y){
	int ix[]={0,-1,0,1},iy[]={-1,0,1,0};
	int r=board[0].size();
	queue<int> q;
	q.push(x*r+y);
	board[x][y]='.';
	while(!q.empty()){
		int pos=q.front(); q.pop();
		int px=pos/r,py=pos%r;
		for(int i=0;i<4;i++){
            int nx=px+ix[i],ny=py+iy[i];
            if(nx<0||nx>=board.size()||ny<0||ny>=board[0].size()) continue;
            if(board[nx][ny]=='O'){
                board[nx][ny]='.';
                q.push(nx*r+ny);
            }
		}
	}
}
/**
要使用c，r记录 长度，否则超时
*/
void solve(vector<vector<char> > &board){
    int c=board.size();
    if(c==0) return;
    int r=board[0].size();
    if(r==0) return;
    for(int i=0;i<r;i++){
        if(board[0][i]=='O'){
            bfs(board,0,i);
        }
        if(board[c-1][i]=='O'){
            bfs(board,c-1,i);
        }
    }
    for(int i=0;i<c;i++){
        if(board[i][0]=='O'){
            bfs(board,i,0);
        }
        if(board[i][r-1]=='O'){
            bfs(board,i,r-1);
        }
    }
    for(int i=0;i<c;i++){
		for(int j=0;j<r;j++){
			if(board[i][j]=='.'){
				board[i][j]='O';
			}else if(board[i][j]=='O'){
                board[i][j]='X';
			}
		}
	}
}

int main(){
	vector<vector<char> > tmp;
	char ch[]={'X','X','X','X'};
	vector<char> t(ch,ch+4);
	tmp.push_back(t);
	char ch1[]={'X','O','O','X'};
	vector<char> t1(ch1,ch1+4);
	tmp.push_back(t1);
	char ch2[]={'X','X','O','X'};
	vector<char> t2(ch2,ch2+4);
	tmp.push_back(t2);
	char ch3[]={'X','O','X','X'};
	vector<char> t3(ch3,ch3+4);
	tmp.push_back(t3);
	for(int i=0;i<tmp.size();i++){
		for(int j=0;j<tmp[i].size();j++){
			cout<<tmp[i][j];
		}cout<<endl;
	}
	solve2(tmp);
	for(int i=0;i<tmp.size();i++){
		for(int j=0;j<tmp[i].size();j++){
			cout<<tmp[i][j];
		}cout<<endl;
	}
	return 0;
}
