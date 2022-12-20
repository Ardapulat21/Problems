#include <iostream>
#include <vector>
using namespace std;
class Solution {

public:
    vector <string> arr;
    string longestPalindrome(string s) { // xcxaxcx
        int value=1;
        vector <string> arr;
        string temp="";
        string result="";
        for(int i=1;i<s.length()-1;i++){ // babad
                while((i+value<s.length())&& s.length()%2!=0){
                    cout<<"s[i-value] "<<s[i-value]<<" s[i+value] "<<s[i+value]<<endl;
                    cout<<"i: "<<i<<" RESULT: "<<result<<endl;
                    cout<<"value: "<<value<<endl;
                    if(s[i-value]==s[i+value]){
                        for(int x=i-value;x<i+value+1;x++){
                            cout<<"x "<<x<<" s[x] "<<s[x]<<endl;
                            temp+=s[x];
                        }
                        result=temp;
                        temp="";
                        value++;
                        arr.push_back(result);
                    }

                    else{
                        cout<<"Value sifirlandi!"<<endl;
                        value=1;
                        break;
                    }
                    }
                    if(s.length()%2==0){
                        temp="";
                        while((i+value)<s.length()){
                            if((s[i]==s[i+value])){
                                for(int x=i;x<i+value+1;x++){
                                    temp+=s[x];
                                }
                                result=temp;
                                temp="";
                                value++;
                            }
                            else{
                                cout<<"value sifirlandi!"<<endl;
                                value=1;
                                break;
                            }

                        }
                        for(int x=;x<s.length())

                    }
i
                    cout<<endl;
                }
            return result;
    }
};

int main()
{
    Solution* s=new Solution();
    cout<<s->longestPalindrome("xcxaxcx");

    return 0;
}
