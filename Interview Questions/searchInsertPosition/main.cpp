#include <iostream>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(target<nums[i]){
                return i;
            }
        }
        return 1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
