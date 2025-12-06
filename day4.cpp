#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <sstream>

using namespace std;

bool safe(vector<string>board,int row,int col){
    if(row<0 || col<0 || row>=board.size() || col>=board[0].size()){
        return false;
    }
    return true;
}

int countNeighbours(vector<string>board,int row,int col){
    int count = 0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(i==0 && j==0) continue;
            if(safe(board,row+i,col+j) && board[row+i][col+j]=='@'){
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<string>board;
    string line;
    while(getline(cin,line)){
        board.push_back(line);
    }
    int n = board.size();
    int m = board[0].size();

    int ans = 0,prev_ans = -1;
    START:// remove this for partA
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='@'){
                int neighbours = countNeighbours(board,i,j);
                if(neighbours < 4) {
                    ans++;
                    board[i][j] = '.'; // remove this for partA
                }
            }
        }
    }
    if(ans != prev_ans){
        prev_ans = ans;
        goto START;
    } //remove this for partA
    
    cout << ans << endl;
    return 0;
}