#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> height) {
            int maxArea=0;int temp=0;
            for(int i=0;i<height.size();i++){
                for(int a=i;a<height.size();a++){
                        if(height[a]>height[i])
                            temp=height[i]*(a-i);
                        else
                            temp=height[a]*(a-i);

                        if(temp>maxArea){
                            maxArea=temp;
                    }
                }
            }
            return maxArea;
    }
};

int main(){
    vector <int> x={1,8,6,2,5,4,8,3,7};
    Solution* s=new Solution();
    cout<<s->maxArea(x);
    return 0;
}
