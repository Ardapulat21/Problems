#include <iostream>
#include <vector>
using namespace std;
bool isInside(vector<string> row,string key){
    for(int i=0;i<row.size();i++){
        if(row[i]==key)
            return true;
    }
    return false;
}
bool isValidSudoku(vector<vector<string>>& board) {
    vector<string> vrow;
    for(int i=0;i<board.size();i++){
        for(int a=0;a<board[i].size();a++){ 
            if(board[i][a]!="."){          
            if(!isInside(vrow,board[i][a])){
                vrow.push_back(board[i][a]);
            }
            else{
                cout<<board[i][a]<<endl;
                return false;
            }   
            }                   
        }                        
        vrow.clear();        
    }     
    
    for(int i=0;i<board[0].size();i++){
        for(int a=0;a<board.size();a++){
            if(board[a][i]!="."){
            if(!isInside(vrow,board[a][i])){
                vrow.push_back(board[a][i]);
            }
            else{
                cout<<board[a][i]<<endl;
                return false;
            }}
        }
        vrow.clear();        
    }
    int row=0;int column=0;
    int counter=0;int rbborder=0;int rtborder=3;int cbborder=0;int ctborder=3;
    for(int row=rbborder;row<rtborder;row++){
        for(int column=cbborder;column<ctborder;column++){ 
            if(counter==9){
                vrow.clear();         
                cout<<"Tahta temizlendi!"<<endl;
                counter=0;
            }
            cout<<"----------"<<endl;
            cout<<"Row: "<<row<<endl;
            cout<<"Column: "<<column<<endl;             
            if(!isInside(vrow,board[row][column])){
                if(board[row][column]!="."){
                    cout<<"Board: "<<board[row][column]<<endl;
                    vrow.push_back(board[row][column]);        
                }
            }
            else{
                cout<<"Bulundu! "<<board[row][column]<<endl;
                return false;       
            }
            if(column!=board[row].size()-1){
                if((row==rtborder-1) && (column==ctborder-1)){
                    row=rbborder;
                    cbborder+=3;
                    ctborder+=3;
                }
            }
            else{
                if((row==2 || row==5)){
                    rbborder+=3;
                    rtborder+=3;
                    cbborder=0;
                    ctborder=3;
                }                             
            }                                                 
            counter++;

        }
    }
    return true;
}
int main(){
    vector<vector<string>> board;
    vector<string> row1={"5","3",".",".","7",".",".",".","."};
    vector<string> row2={"6",".",".","1","9","5",".",".","."};
    vector<string> row3={".","9","8",".",".",".",".","6","."};
    vector<string> row4={"8",".",".",".","6",".",".",".","3"};
    vector<string> row5={"4",".",".","8",".","3",".",".","1"};
    vector<string> row6={"7",".",".",".","2",".",".",".","6"};
    vector<string> row7={".","6",".",".",".",".","2","8","."};
    vector<string> row8={".",".",".","4","1","9",".",".","5"};
    vector<string> row9={".",".",".",".","8",".",".","7","9"};
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    board.push_back(row4);
    board.push_back(row5);
    board.push_back(row6);
    board.push_back(row7);
    board.push_back(row8);
    board.push_back(row9);

    cout<<isValidSudoku(board);
}   