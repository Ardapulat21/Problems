#include <iostream>
using namespace std;
int reverse(int x){
    int counter=0;
    int temp=x;
    while(temp>0){
        counter++;
        temp/=10;
    }
    int number;
    int multiple=1;
    int result=0;
    while(x>0){
    number=x%10;
    multiple=1;
    for(int i=0;i<counter-1;i++){
        multiple*=10;
    }    
    multiple=number*multiple;
    counter--;   
    result+=multiple;
    x/=10;
    }    
    return result;
}
int main(){
    cout<<reverse(120);
}