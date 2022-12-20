#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int whichNumber(char c){
        switch(c){
        case '0':
            return 0;
            break;
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
        }
    }
    int SttoInt(string s){//123
        int result=0;int temp=0;int length=s.length()-1;
        for(int i=0;i<s.length();i++){
            temp=whichNumber(s[i]);
            for(int x=0;x<length;x++){
                temp*=10;
            }
            length--;
            result+=temp;
        }
        return result;
    }
    int reverse(int x) {
        bool isNegative=0;
        if(x<0){
            isNegative=1;
            x*=-1;
        }
        string number=to_string(x);//işeretsiz sayi;
        string result="";
        for(int i=number.length()-1;i>=0;i--){
            result+=number[i];
        }
        int num = SttoInt(result);
        if(isNegative)
            num*=-1;
        return num;
    }
};

int main()
{
    Solution* s=new Solution();
    cout<<s->reverse(3214);
    return 0;
}
