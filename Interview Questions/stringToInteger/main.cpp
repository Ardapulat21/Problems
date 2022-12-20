#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int c=0;
    bool isitnumber(char x){

        if(x=='1' || x=='2' || x=='3' || x=='4' || x=='5' || x=='6' || x=='7' || x=='8' || x=='9' || x=='0'){
            return 1;
        }
        else if((x=='+' || x=='-')&& c==0){
            c=1;
            return 1;
        }
        else{
            return 0;
        }
    }
    int whichNumber(char c){
        switch(c){
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        case '0':
            return 0;
            break;
        }
    }
    int myAtoi(string s) {//   421  ->xxx421xx
        string x="";
        bool signification=1;
        int result=0;
        int temp=0;
        int num=0;
        for(int i=0;i<s.length();i++){
            if(isitnumber(s[i])){//karakter numara deðil ise içeriye girecek
                x+=s[i];
            }
        }// x'in içinde yalnızca + - ve rakam olabilir.
        cout<<"X: "<<x<<endl;
        if(x[0]=='-'){
            cout<<"eksi"<<endl;
            x=x.substr(1,-1);
            signification=0;
        }
        else if(x[0]=='+'){
            cout<<"Arti"<<endl;
            x=x.substr(1,-1);
        }
        else{
            cout<<"arti"<<endl;
        }
        bool cc=0;
        int indexx=0;
        for(int i=0;i<x.length();i++){
            if(x[i]!='0'){
                cc=1;
            }
            else if(cc==0 && x[i]=='0'){
                cout<<"x["<<i<<"]: "<<x[i]<<"siliyorum"<<endl;
                indexx++;
            }
        }
        x=x.substr(indexx,-1);
        cout<<"X:"<<x<<endl;
        // artık sadece sayı var boşluksuz ve işaretsiz. 001234
        int length=x.length();
        for(int i=0;i<x.length();i++){//1234
            num=whichNumber(x[i]);
            temp=num;
            for(int z=0;z<length-1;z++){
                temp=temp*10;
                cout<<"Temp: "<<temp<<endl;
            }
            length--;
            result+=temp;
            cout<<"Result: "<<result<<endl;
        }
        if(!signification)
                result*=-1;
        return result;
    }
};

int main()
{
   Solution* s=new Solution();
   cout<<s->myAtoi("adsd-001023");



    return 0;
}
