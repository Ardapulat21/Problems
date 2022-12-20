#include <iostream>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows){
        string result="";int row=0;int column=0;int counter=0;
        string array[numRows][int(s.length()/2)];
        for(int z=0;z<sizeof(array)/sizeof(array[0]);z++){
            for(int zx=0;zx<sizeof(array[0])/sizeof(array[0][0]);zx++){
                array[z][zx]="";
            }
         }

        for(int i=0;i<s.length();i++){
        array[row][column]=s[i];
            if(counter==0){
                if((row!=numRows-1) || (row==0)){
                    row++;
                }
                else if(row==numRows-1){
                    counter=numRows-2;
                    row--;
                    column++;
                }
            }
            else{
                row--;
                column++;
                counter--;
            }
        }
        for(int i=0;i<sizeof(array)/sizeof(array[0]);i++){
            for(int a=0;a<sizeof(array[0])/sizeof(array[0][0]);a++){
                cout<<array[i][a]<<" ";
                result+=array[i][a];
            }
            cout<<endl;
        }
        return result;
    }
};

int main()
{
    Solution* s=new Solution();
    cout<<s->convert("PAYPALISHIRING",4);
    return 0;
}
