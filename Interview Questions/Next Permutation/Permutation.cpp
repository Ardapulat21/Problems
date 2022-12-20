#include <iostream>
#include <vector>
using namespace std;
void nextPermutation(vector<int>& nums) {
    vector<vector<int>> vect;
    vector<int> vect2;
    for(int i=0;i<nums.size()-1;i++){
        for(int a=i+1;a<nums.size();a++){
            vect2.push_back(nums[i]);
            vect2.push_back(nums[a]);
            vect.push_back(vect2);
            vect2.clear();
        }
    }
    for(int i=nums.size()-1;i>=1;i--){
        for(int a=i-1;a>=0;a--){
            vect2.push_back(nums[i]);
            vect2.push_back(nums[a]);
            vect.push_back(vect2);
            vect2.clear();
        }
    }
    for(int i=0;i<vect.size();i++){
        cout<<vect[i][0]<<" "<<vect[i][1]<<endl;
    }
}
int main(){
    vector<int> arr={1,2,3};
    nextPermutation(arr);
}