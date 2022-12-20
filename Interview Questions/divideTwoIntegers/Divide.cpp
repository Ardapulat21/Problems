#include <iostream>
using namespace std;
int divide(int dividend, int divisor) {
    int sign=1;int result=0;
    if(dividend*divisor<0){
        sign=-1;
        if(dividend<0)
            dividend*=-1;
        else
            divisor*=-1;            
    }
    int increase=divisor;
    int counter=0;
    while(true){  
        if(dividend<=divisor)
            break;
        counter++;              
        divisor+=increase;
        
    }
    return sign*counter;        
}
int main(){
    cout<<divide(-1,-1);
}