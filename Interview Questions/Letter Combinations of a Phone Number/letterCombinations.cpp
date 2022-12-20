#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<string> combinations(vector<string> a,vector<string> b){
    vector<string> res;
    for(int i=0;i<a.size();i++){
        for(int x=0;x<b.size();x++){
            res.push_back(a[i]+b[x]);
        }
    }
    return res;
}

vector<string> letterCombinations(string digits) {
    map<char,vector<string>> letter;
    vector<string> outcome;
    vector<string> second;
    vector<string> first;   
    letter.insert(pair<char,vector<string>>('2',{"a","b","c"}));
    letter.insert(pair<char,vector<string>>('3',{"d","e","f"}));
    letter.insert(pair<char,vector<string>>('4',{"g","h","i"}));
    letter.insert(pair<char,vector<string>>('5',{"j","k","l"}));
    letter.insert(pair<char,vector<string>>('6',{"m","n","o"}));
    letter.insert(pair<char,vector<string>>('7',{"p","q","r","s"}));
    letter.insert(pair<char,vector<string>>('8',{"t","u","v"}));
    letter.insert(pair<char,vector<string>>('9',{"w","x","y","z"}));    
    first=letter.find(digits[0])->second;
    for(int i=0;i<digits.size()-1;i++){
        second=letter.find(digits[i+1])->second;
        first=combinations(first,second);
    }
    return first;
}
int main(){
    vector<string> vect=letterCombinations("234");
    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<endl;
    }
}