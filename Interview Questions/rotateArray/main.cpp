#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> v;
        k=k%nums.size();
        cout<<"k:"<<k<<endl;
        for(int i=nums.size()-k;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-k;i++){
            v.push_back(nums[i]);
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<endl;
        }

    }
};
int main()
{
    vector<int> x={-1,-100,3,99};
    vector <int> y={1,2,3,4,5,6,7};
    Solution* s=new Solution();
    s->rotate(x,2);


    return 0;
}
