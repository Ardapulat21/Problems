#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int Icounter=0;
        int counter=0;
        int index1=0;
        int index2=0;
        int index3=0;
        int result=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='I'){
                Icounter++;

                index1=i;
            }
            else if(s[i]=='L'){
                result+=50;
                index3=i;
            }
            else if(s[i]=='V'){
                result+=5;
                index2=i;
            }
            else if(s[i]=='X'){
                if(s[i+1]=='C'){
                    result+=90;
                }else{
                    result+=10;
                }

            }
            else if(s[i]=='L'){
                result+=50;
            }
            else if(s[i]=='M' && s[i-1]!='C'){
                result+=1000;
            }
            else if(s[i]=='C' && s[i+1]=='M'){
                result+=900;
            }

        }
        if(Icounter==s.length()){
                result=Icounter;
            }
        if(index2>index1){
            result-=Icounter;}
        else if(index3>index1){
            result-=Icounter;
        }
        else if(index1>index2 && index2!=0){
            result+=Icounter;
        }
        else if(index1>index3 & index3!=0){
            result+=Icounter;

   }
            cout<<result;
    }
};

int main()
{
    Solution* s=new Solution();
    s->romanToInt("MCMXCIV");
    }

