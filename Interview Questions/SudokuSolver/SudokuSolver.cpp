#include <iostream>
#include <vector>
using namespace std; 
bool isNumberinRow(vector<vector<int>> & board,int row,int number){
    for(int i=0;i<9;i++){
        if(board[row][i]==number)
            return true;
    }
    return false;
}
bool isNumberinColumn(vector<vector<int>> & board,int column,int number){
    for(int i=0;i<9;i++){
        if(board[i][column]==number)
            return true;
    }
    return false;   
}
bool isNumberinSubbox(vector<vector<int>> &board,int column,int row,int number){
    int bRow=row-row%3;
    int bColumn=column-column%3;
    for(int i=bRow;i<bRow+3;i++){
        for(int a=bColumn;a<bColumn+3;a++){
            if(board[i][a]==number)
                return true;
        }
    }
    return false;
}
bool isValidPlacement(vector<vector<int>> &board,int number,int row,int column){
    return !isNumberinColumn(board,column,number) && 
           !isNumberinRow(board,row,number) && 
           !isNumberinSubbox(board,column,row,number);
}
bool solveSudoku(vector<vector<int>>& board){
    for(int i=0;i<9;i++){
        for(int a=0;a<9;a++){
            if(board[i][a]==0){
                for(int x=1;x<=9;x++){                
                    if(isValidPlacement(board,x,i,a)){  
                        board[i][a]=x;                      
                        if(solveSudoku(board)){
                            return true;
                        }   
                        else{
                            board[i][a]=0;
                        }                         
                    }
                }
                return false;
            }
        }
    }
    
    return true;
}  
int main(){
   vector<vector<int>> board;
    vector<int> row1={5,3,0,0,7,0,0,0,0};
    vector<int> row2={6,0,0,1,9,5,0,0,0};
    vector<int> row3={0,9,8,0,0,0,0,6,0};
    vector<int> row4={8,0,0,0,6,0,0,0,3};
    vector<int> row5={4,0,0,8,0,3,0,0,1};
    vector<int> row6={7,0,0,0,2,0,0,0,6};
    vector<int> row7={0,6,0,0,0,0,2,8,0};
    vector<int> row8={0,0,0,4,1,9,0,0,5};
    vector<int> row9={0,0,0,0,8,0,0,7,9};
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    board.push_back(row4);
    board.push_back(row5);
    board.push_back(row6);
    board.push_back(row7);
    board.push_back(row8);
    board.push_back(row9);

    solveSudoku(board);
    
    for(int i=0;i<board.size();i++){
        for(int a=0;a<board[i].size();a++)
            cout<<board[a][i]<<" ";
        cout<<endl;
    }
}