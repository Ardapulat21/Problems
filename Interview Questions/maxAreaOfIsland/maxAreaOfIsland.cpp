#include <iostream>
#include <vector>
using namespace std;
int min(int a,int b){
    if(a<b)
        return a;
    return b;
}
int maxArea(vector<int>& height){
    int result=0;int Area=1;
    for(int i=0;i<height.size()-1;i++){
        for(int a=i+1;a<height.size();a++){
            Area=(a-i)*min(height[a],height[i]);
            if(Area>result)
                result=Area;
        }
    }
    cout<<result;
    return result;
}
int main(){
    vector<int> vect={1,8,6,2,5,4,8,3,7};
    maxArea(vect);

    
}