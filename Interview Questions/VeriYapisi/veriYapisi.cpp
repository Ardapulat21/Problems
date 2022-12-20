#include <iostream>
#include <ctime>
#include <cstdlib>
#define stacksize 1000
using namespace std;
typedef struct{
    int data[stacksize];
    int top;
}stack;
void initialize(stack *stck){
    stck->top=-1;    
}
void push(stack *stck,int data){
    if(stck->top==stacksize-1)
        printf("%s","Stack is full");
    else{
        stck->top++;
        stck->data[stck->top]=data;
    }
}
int pop(stack* stck){
    int result=stck->data[stck->top];
    stck->top--;
    return result;}
void printAll(stack* stck){
    while(stck->top!=-1){
        cout<<pop(stck)<<" ";
    }
}
int isInside(stack* stck,int target){
    while(stck->top!=-1){
        if(stck->data[stck->top]==target){
            cout<<"The number was Found!"<<endl;
            cout<<"Order:"<<stck->top<<endl;
            return stck->top;                    
        }
        stck->top--;
    }
    cout<<"The number that you searched for was not found in stack";
    return -1;
}
int main(){
    stack n;
    initialize(&n);

    srand(time(0));
    int randd;
    for(int i=0;i<100;i++){
        randd=(rand() % 1001);
        push(&n,randd);     
    }
    push(&n,3);

    isInside(&n,3);

    
}