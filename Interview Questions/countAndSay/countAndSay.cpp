#include <iostream>
#include<string>
using namespace std;

string countAndSay(int n) { // 3322251     two three three two one five one one 23321511
    string outcome="";
    int counter=0;
    for(int i=1;i<=n;i++){
        if(i==1)
            outcome+="1";
        else if(i==2){
            outcome+="1";
        }
        else{
            for(int x=0;x<outcome.length()-1;x++){
                if(outcome[x]==outcome[x+1])
                    counter++;                              
                else{
                    counter++;
                    string str=to_string(counter);
                    outcome+=str+outcome[x];
                }  
            }
        }                    
        }
        return outcome;
    }
int main(){
    cout<<countAndSay(4);
}