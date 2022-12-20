#include <iostream>
#include <vector>
using namespace std;
bool isThere(vector<string> nums,string num){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==num)
            return true;
    }
    return false;
}
vector<vector<string>> setValue(vector<vector<string>> board,int i,int a){
    vector<string> nums;
    vector<string> possibilities={"1","2","3","4","5","6","7","8","9"};
    
    return board;
}
void solveSudoku(vector<vector<string>>& board) {
    int counter=0;int rbborder=0;int rtborder=3;int cbborder=0;int ctborder=3;
    vector<string> nums;
    vector<vector<string>> squareposs;
    vector<string> temp;
    for(int row=rbborder;row<rtborder;row++){
        for(int column=cbborder;column<ctborder;column++){           
            if(board[row][column]!=".")
                temp.push_back(board[row][column]);            
            
            if((column==ctborder-1) && (row==rtborder-1) && (column!=board[row].size()-1)){   
                ctborder+=3;
                cbborder+=3;
                row=rbborder;
            }            
            if((column==board[row].size()-1) && (row==rtborder-1) && (row!=board.size()-1)){
                rbborder+=3;
                rtborder+=3;
                cbborder=0;
                ctborder=3;
            }             
                counter++;
            if(counter==9){
                counter=0;
                squareposs.push_back(temp);
                temp.clear();                
            } 
        }        
    }   
    for(int i=0;i<squareposs.size();i++){
        for(int a=0;a<squareposs[i].size();a++)
            cout<<squareposs[i][a]<<" ";
        cout<<endl;
    }
    vector<string> possibilities={"1","2","3","4","5","6","7","8","9"};
    // Squareposs 9'lu karelerdeki elemnalar.
    counter=0;rbborder=0;rtborder=3;cbborder=0;ctborder=3;int index=0;
    for(int row=rbborder;row<rtborder;row++){
        for(int column=cbborder;column<ctborder;column++){                                                                              
            if(board[row][column]=="."){  
                cout<<"Row: "<<row<<endl;                     
                cout<<"Column: "<<column<<endl;                                                            
                for(int a=0;a<possibilities.size();a++){
                    for(int x=0;x<squareposs[index].size();x++){
                        if(possibilities[a]==squareposs[index][x])
                            possibilities[a]="";
                            //possibilities.erase(possibilities.begin()+a);                                                                    
                    }                    
                }
                
                for(int i=0;i<possibilities.size();i++){
                    for(int a=0;a<board.size();a++){
                        if(possibilities[i]==board[a][column]){
                            cout<<board[a][column]<<" Deleted(column)"<<endl;
                            //possibilities.erase(possibilities.begin()+i);
                            possibilities[i]="";
                        }
                    }           
                }  
            
                for(int i=0;i<possibilities.size();i++){
                    for(int a=0;a<board[row].size();a++){
                        if(possibilities[i]==board[row][a]){
                            cout<<possibilities[i]<<" Deleted (row)"<<endl;
                            //possibilities.erase(possibilities.begin()+i);
                            possibilities[i]="";
                        }
                    }
                }   
                cout<<"----------"<<endl;
                for(int i=0;i<possibilities.size();i++)
                    cout<<possibilities[i]<<" ";    
                
                cout<<endl;
                cout<<"----------"<<endl;
                
                 

                if(possibilities[0]!=""){
                    cout<<possibilities[0]<<" Added on the board!"<<endl;                      
                    board[row][column]=possibilities[0];
                }else{
                    for(int i=0;i<possibilities.size();i++){
                        if(possibilities[i]!=""){
                            cout<<possibilities[i]<<" Added on the board!"<<endl;                      
                            board[row][column]=possibilities[i];                            
                        }
                    }
                }                

            }            

            if((column==ctborder-1) && (row==rtborder-1) && (column!=board[row].size()-1)){   
                ctborder+=3;
                cbborder+=3;
                row=rbborder;
            }            
            if((column==board[row].size()-1) && (row==rtborder-1) && (row!=board.size()-1)){
                rbborder+=3;
                rtborder+=3;
                cbborder=0;
                ctborder=3;
            }             
            
            
            if(counter==9){
                possibilities={"1","2","3","4","5","6","7","8","9"};
                index++;     
                cout<<"Possibilities created again!"<<endl;
                counter=0;
            }    
            counter++;

        }
    } 
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
    solveSudoku(board);
    for(int i=0;i<board.size();i++){
        for(int a=0;a<board[i].size();a++)
            cout<<board[a][i]<<" ";
        cout<<endl;
    }
}