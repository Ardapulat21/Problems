#include <iostream>
using namespace std;
int func(int num){
    int res=0;
    if(num<=0)
        cout<<"Hata!"<<endl;
    else if(num==1)
        return num;
    else{
        res=num*func(num-1);
        return res;
    }
    return -1;
}
int main(){
    cout<<func(6);
    
}