#include <iostream>
#include <vector>
using namespace std;
bool isThere(string s,char c){
    for(int i=0;i<s.length();i++){
        if(c==s[i])
            return 1;
    }
    return 0;
}

int main()
{
    vector <string> v;
    string x="pwwkew";string result="";
    for(int a=0;a<x.length();a++){
        for(int i=a;i<x.length();i++){
            if(!isThere(result,x[i])){
                result+=x[i];
            }
            else{
                v.push_back(result);
                result="";
                break;
            }
        }
    }
    int length=0;
    for(int i=0;i<v.size();i++){
        if(length<v[i].length())
            length=v[i].length();
    }
    cout<<length<<endl;
    cout<<"----"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    return 0;
}
