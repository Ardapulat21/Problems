#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
int row;
int column;
    vector<vector<int>> Area(vector<vector<int>>arr,int i,int a,int color){
        row=arr.size()-1;
        column=arr[1].size()-1;
        arr[i][a]=color;
        for(int x=0;x<arr.size();x++){
            for(int xx=0;xx<arr[1].size();xx++){
                cout<<arr[x][xx]<<" ";
            }
            cout<<endl;
        }
        cout<<"Row: "<<i<<" Column: "<<a<<endl;        
        if((a>0 && a<column) && (i>0 && i<row)){// this is for index of Array in inside;
            if(arr[i][a+1]==1){
                Area(arr,i,a+1,color);
            }
            if(arr[i][a-1]==1){
                Area(arr,i,a-1,color);
            }
            if(arr[i-1][a]==1){
                Area(arr,i-1,a,color);
            }
            if(arr[i+1][a]==1){
                Area(arr,i+1,a,color);    
            }
        }
        else if((a==0 || a==column)&&(i>0 && i<row)){            
                if(a==0){
                    if(arr[i][a+1]==1)
                        Area(arr,i,a+1,color);                                       
                }
                else if(a==column){
                    if(arr[i][a-1]==1)
                        Area(arr,i,a-1,color);                                                        
            }   // burayi parantezden cikarttim cünkü ortak alan.            
                    if(arr[i+1][a]==1)
                        Area(arr,i+1,a,color);

                    if(arr[i-1][a]==1)
                        Area(arr,i-1,a,color); 
            
        }
        else if((i==0 || i==column)&&(a>0 && a<row)){            
                if(i==0){
                    if(arr[i+1][a]==1)
                        Area(arr,i+1,a,color);                                       
                }
                else if(i==row){
                    if(arr[i-1][a]==1)
                        Area(arr,i-1,a,color);                                                        
            }   // burayi parantezden cikarttim cünkü ortak alan.            
                    if(arr[i][a+1]==1)
                        Area(arr,i,a+1,color);

                    if(arr[i][a-1]==1)
                        Area(arr,i,a-1,color);             
        }
        else if(i==0 && a==0){
            if(arr[i+1][a]==1)
                Area(arr,i+1,a,color);


            if(arr[i][a+1]==1)
                Area(arr,i,a+1,color);             
        }
        else if(i==0 && a==column){
            if(arr[i+1][a]==1)
                Area(arr,i+1,a,color);

            if(arr[i][a-1]==1)
                Area(arr,i,a-1,color);             
        }
        else if(i==row && a==0){
            if(arr[i-1][a]==1)
                Area(arr,i-1,a,color);

            if(arr[i][a+1]==1)
                Area(arr,i,a+1,color);             
        }
        else if(i==row && a==column){
            if(arr[i-1][a]==1)
                Area(arr,i-1,a,color);

            if(arr[i][a-1]==1)
                Area(arr,i,a-1,color);             
        }
        
        return arr;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        image=Area(image,sr,sc,color);
        
    }
};

int main()
{
    vector<vector<int>> image={{1,1,1},{1,1,0},{1,0,1}};
    Solution* s= new Solution();
    s->floodFill(image,1,1,2);

    return 0;
}
