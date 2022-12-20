#include <iostream>
using namespace std;
string longestPalindromicSubstr(string substr){//   BABAD
    int left=0;int right=0;
    string result;
    int length=0;
    for(int i=0;i<substr.length();i++){
        left=right=i;
        while(left>=0 && right<substr.length() && (substr[left]==substr[right])){
            if(right-left+1>length){
                result=substr.substr(left,right+1);
                length=right-left+1;
            }
            left--;
            right++;
        }
    }
    return result;
}
int main(){
    cout<<longestPalindromicSubstr("cbbd");
}