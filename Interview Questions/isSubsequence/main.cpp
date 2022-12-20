#include <iostream>

using namespace std;
class Solution {
public:
    bool isThere(string t,char x){
        for(int i=0;i<t.length();i++){
            if(t[i]==x){
                return 1;
            }
        }
        return 0;
    }
    int indexOf(char x,string t){
        int index=0;
        for(int i=0;i<t.length();i++){
            if(x==t[i]){
                index=i;
            }
        }
        return index;
    }
    bool isSubsequence(string s, string t) {
        int counter=0;
        int c=0;//1 olursa return 0
        for(int i=0;i<s.length();i++){
            if(isThere(t,s[i])){
                counter++;
            }
        }
        if(counter==s.length()){
            for(int i=0;i<s.length()-1;i++){
                if(indexOf(s[i],t)>indexOf(s[i+1],t)){
                    c=1;
                }
            }
        }
        cout<<c<<endl;
        if(c==1 || counter!=s.length()){
            cout<<"no way"<<endl;
            return 0;
        }
        else{ // c==0 && counter==s.length()
            cout<<"exactly"<<endl;
            return 1;
        }

    }
};
int main()
{
    Solution* s=new Solution();
    s->isSubsequence("abc","ahbgdc");
    return 0;
}
