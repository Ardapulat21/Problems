#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack<string> stack2;

void printStack(stack<string> stack){
    cout<<"++++++++"<<endl;
    while (!stack.empty()) {        
        stack2.push(stack.top());
        stack.pop();
    }
    while(!stack2.empty()){
        cout<<stack2.top()<<endl;
        stack2.pop();
    }  
    cout<<"++++++++"<<endl;

}
stack<string> deleteStack(stack<string> stack,int index){
    while (!stack.empty()) {
        if(index==stack.size()-1){
            stack.pop();            
            break;
        }        
        stack2.push(stack.top());
        stack.pop();
    }
    while(!stack2.empty()){
        stack.push(stack2.top());
        stack2.pop();
    }
    return stack;
}
int main(){    
    int selection;string task;int index;
    stack<string> stack;
    if(stack.size()==0){        
        cout<<"**There is no task in your TO DO LIST.You need to be disciplined!"<<endl;
        cout<<"**If you want to quit to insert press 0"<<endl;
        cout<<"**What task would you like to insert? Write it down!"<<endl;

        while(task!="0"){
            cin>>task;
            if(task!="0")
                stack.push(task);                            
            else{
                task="1";
                break;
            }
        }
        }      
    while(true){    
    cout<<"**To Do list for today:\nWhat would you like to do?\nPress 1)Insert a task \nPress 2)Delete a task\nPress 3)Show to do list \nPress 4)Quit"<<endl;
    cin>>selection;
    
    if(selection==1){
        cout<<"----------"<<endl;

        cout<<"**What task would you like to insert? Write it down!"<<endl;        
        while(task!="0"){
            cin>>task;
            if(task!="0")
                stack.push(task);
        }}
    else if(selection==2){
        cout<<"----------"<<endl;
        cout<<"Which task would you like to delete? Choose one!"<<endl;
        printStack(stack);
        cin>>index;
        stack=deleteStack(stack,index-1); 
        printStack(stack);    
        }
    else if(selection==3){
        cout<<"----------"<<endl;
        printStack(stack);
    }
    else if(selection==4)
        break;
    }
}