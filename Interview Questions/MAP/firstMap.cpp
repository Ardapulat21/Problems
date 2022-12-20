#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    map<string,string> firstMap;
    firstMap.insert(pair<string,string>("sukriye","pulat"));
    firstMap.insert(pair<string,string>("arda","pulat"));
    firstMap.insert(pair<string,string>("osman","pulat"));
    firstMap.insert(pair<string,string>("ahmet","pulat"));

    for(auto x:firstMap) cout<<x.first<<" "<<x.second<<endl;
}