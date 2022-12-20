#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
    vector<char> vector1;
    vector<char> vector2;


    bool isThere(vector<char> v,char x){
        int c=0;
        for(int i=0;i<v.size();i++){
            if(x==v[i]){
                c=1;
            }
        }
        if(c==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    int indexOf(vector<char> v,char x){
        int c=0;
        for(int i=0;i<v.size();i++){
            if(x==v[i]){
                c=i;
            }
        }
        return c;
    }
    bool isIsomorphic(string s,string t){
        vector1.clear();
        vector2.clear();
        int xx=1;
        for(int i=0;i<s.length();i++){

            cout<<"si: "<<s[i]<<endl;
            cout<<"ti: "<<t[i]<<endl;
            if(!isThere(vector1,s[i]) && !isThere(vector2,t[i])){// eğer yoksa içeri girecek varsa girmiyor.
                vector1.push_back(s[i]);
                vector2.push_back(t[i]);
                cout<<"vector1 "<<s[i]<<" eklendi."<<endl;
                cout<<"vector2 "<<t[i]<<" eklendi."<<endl;
            }
            else{// eğer eklemek istediğimiz char vector1 in içinde ise.
                if(vector2[indexOf(vector1,s[i])]!=t[i] || vector1[indexOf(vector2,t[i])]!=s[i]){
                    cout<<"s: "<<s<<endl;
                    cout<<"t: "<<t<<endl;
                    xx=0;
                    break;
                }
            }
            cout<<"--"<<endl;
        }
        if(xx==0){
            cout<<"No.It's not isomorphic."<<endl;
            return 0;


        }
        else{
            cout<<"Yes.It is isomorphic."<<endl;
            return 1;
        }
    }
};


int main()
{
    Solution* s=new Solution();

    s->isIsomorphic("ab","aa");
    cout<<"---"<<endl;

    return 0;
}
