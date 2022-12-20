#include <iostream>

using namespace std;
class Solution {
public:
    string wordd(string s,int start,int index){
        string result="";
        for(int i=index;i>=start;i--){
            if(s[i]!=' ')
                result+=s[i];
        }
        return result;
    }
    string reverseWords(string s) {
        string word="";string reword="";string result="";
        int index=0;int start=0;
        while(index<=s.length()-1){
            if(s[index]==' '){
                word=wordd(s,start,index);
                result+=word+" ";
                start=index;
                cout<<"word: "<<word<<endl;
            }
            index++;
        }
        result=result.substr(0,result.length()-1);
        result+=wordd(s,start,index);
        cout<<result<<endl;
    }
};
bool isEqual(string s,string s2){
    for(int i=0;i<s.length();i++){
        if(s[i]!=s2[i]){
            cout<<"s1: "<<s[i]<<" s2: "<<s2[i]<<endl;
            return 0;
        }
    }
    return 1;
}
int main()
{
    Solution* s=new Solution();
    //s->reverseWords("Let's take LeetCode contest");
    isEqual("s'teL ekat edoCteeL tsetnoc","s'teL ekat edoCteeL tsetnoc");
    return 0;
}
