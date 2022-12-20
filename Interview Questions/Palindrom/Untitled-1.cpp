#include<iostream>
using namespace std;
bool Palindrom(int x){
    string str=to_string(x); // 4114 first 0 last 3
    int first=0;int last=str.length()-1;
    if(str.length()%2==0){
        while(true){
            if(str[first]!=str[last])
                break;
            else if((last-first)==1){
                return true;
            }
            else{
                first++;
                last--;
            }                
        }
    }else{
        while(true){
            if(str[first]!=str[last])
                break;
            else if((last-first)==2)
                return true;
            else{
                first++;
                last--;
            }            
        }
    }
    return false;     
}
int main(){
    cout<<Palindrom(6226);
}