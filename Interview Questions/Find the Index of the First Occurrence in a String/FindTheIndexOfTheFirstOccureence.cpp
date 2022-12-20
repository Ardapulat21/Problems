#include <iostream>
using namespace std;
int strStr(string haystack, string needle) {
    int first=0;
    while(first<haystack.size()){
        if(haystack.substr(first,needle.size())==needle)
            return first;
        else{
            first++;
        }                
    }
    return -1;        
}
int main(){
    cout<<strStr("leetcode","leect");
}