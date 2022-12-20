#include <iostream>
#include <stack>
using namespace std;
class Solution {    
public: 
    bool isValid(std::string s) { 
        stack<string> stack;       
        for(int index=0;index<s.length();index++){
            switch(s[index]){
                case '(':
                    cout<<"index: "<<s[index]<<" ";
                    cout<<"( is added!"<<endl;
                    stack.push("(");                                      
                    break;
                case '{':                
                    cout<<"index: "<<s[index]<<" ";
                    cout<<"{ is added!"<<endl;
                    stack.push("{");
                    break;
                case '[':                                          
                    cout<<"index: "<<s[index]<<" ";
                    stack.push("[");                                       
                    cout<<"[ is added!"<<endl;
                    break;
                case ')':                                      
                    cout<<"index: "<<s[index]<<" ";
                    if(stack.top()=="("){
                        cout<<stack.top()<<" is removed!"<<endl;
                        stack.pop();   
                    }                   
                    else
                        return false;                                   
                    break;
                case '}':
                    cout<<"index: "<<s[index]<<" ";
                    if(stack.top()=="{"){
                        cout<<stack.top()<<" is removed!"<<endl;
                        stack.pop();   
                    }                                         
                    else{
                        return false;  
                    }
                                                         
                    break;
                case ']':
                    cout<<"index: "<<s[index]<<" ";                    
                    if(stack.top()=="["){
                        cout<<stack.top()<<" is removed!"<<endl;
                        stack.pop();   
                    }                    
                    else
                        return false;                                   
                    break;
            }            
        }        
        if(stack.size()!=0)
            return false;
        return true;
    }
};
int main(){
    Solution* s=new Solution();
    s->isValid("({[})");
    

    printf("%d",s->isValid("["));
}