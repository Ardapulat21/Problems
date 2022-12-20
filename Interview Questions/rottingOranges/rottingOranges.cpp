#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int row;
    int column;
    vector<vector<int>> Area(vector<vector<int>>& arr,int i,int a){ //If this code entered here,this orange is rotten.And we are looking for fresh fruit.
    row=arr.size()-1;
    column=arr[1].size()-1;
    
    cout<<"---------------"<<endl;
               
        cout<<"i: "<<i<<" a: "<<a<<endl;
        arr[i][a]=3;// ilk önce üçe cevirelim daha sonra 3 bulduklarımızı 2 ye ceviririz.karısmasın.
        if((a>0 && a<column) && (i>0 && i<row)){// this is for index of Array in inside;
            if(arr[i][a+1]==1){
                Area(arr,i,a+1);
            }
            if(arr[i][a-1]==1){
                Area(arr,i,a-1);
            }
            if(arr[i-1][a]==1){
                Area(arr,i-1,a);
            }
            if(arr[i+1][a]==1){
                Area(arr,i+1,a);    
            }
        }
        else if((a==0 || a==column)&&(i>0 && i<row)){            
                if(a==0){
                    if(arr[i][a+1]==1)
                        Area(arr,i,a+1);                                       
                }
                else if(a==column){
                    if(arr[i][a-1]==1)
                        Area(arr,i,a-1);                                                        
            }   // burayi parantezden cikarttim cünkü ortak alan.            
                    if(arr[i+1][a]==1)
                        Area(arr,i+1,a);

                    if(arr[i-1][a]==1)
                        Area(arr,i-1,a); 
            
        }
        else if((i==0 || i==column)&&(a>0 && a<row)){            
                if(i==0){
                    if(arr[i+1][a]==1)
                        Area(arr,i+1,a);                                       
                }
                else if(i==row){
                    if(arr[i-1][a]==1)
                        Area(arr,i-1,a);                                                        
            }   // burayi parantezden cikarttim cünkü ortak alan.            
                    if(arr[i][a+1]==1)
                        Area(arr,i,a+1);

                    if(arr[i][a-1]==1)
                        Area(arr,i,a-1);             
        }
        else if(i==0 && a==0){
            if(arr[i+1][a]==1)
                Area(arr,i+1,a);


            if(arr[i][a+1]==1)
                Area(arr,i,a+1);             
        }
        else if(i==0 && a==column){
            if(arr[i+1][a]==1)
                Area(arr,i+1,a);

            if(arr[i][a-1]==1)
                Area(arr,i,a-1);             
        }
        else if(i==row && a==0){
            if(arr[i-1][a]==1)
                Area(arr,i-1,a);

            if(arr[i][a+1]==1)
                Area(arr,i,a+1);             
        }
        else if(i==row && a==column){
            if(arr[i-1][a]==1)
                Area(arr,i-1,a);

            if(arr[i][a-1]==1)
                Area(arr,i,a-1);             
        }
        return arr;                
    }
    void orangesRotting(vector<vector<int>>& grid) {        
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[1].size();c++){                
                if(grid[r][c]==2){
                    Area(grid,r,c);
                }
            }
        }
        cout<<"OrangesRotting"<<endl;
        
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[1].size();c++){                
                if(grid[r][c]==3){
                    grid[r][c]=2;
                }
            }            
        }
        
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[1].size();c++){                
                cout<<grid[r][c]<<" ";
            }
            cout<<endl;
        }        

    }
};

int main(){
    vector<vector<int>> grid={{2,1,1},{1,1,0},{0,1,1}};
    Solution* s=new Solution();
    s->orangesRotting(grid);
           
    return 0;
}