#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    vector<int> result2;
    result2.push_back(-1);
    result2.push_back(-1);
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target)
            result.push_back(i);        
    }
    if(result.size()==0)
        return result2;
        
    return result;
    
}
int main(){
    vector<int> nums={1};
    vector<int>result=searchRange(nums,1);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
}