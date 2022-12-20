#include <iostream>
#include <vector>
using namespace std;
bool find(int val,vector<int>&nums){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==val)
            return true;
    }
    return false;
}
vector<int> arr(vector<int> nums){
    vector<int>vect;
    for(int i=0;i<nums.size();i++){
        if(!find(nums[i],vect))
            vect.push_back(nums[i]);
    }
    return vect;
}

int removeDuplicates(vector<int>& nums) {
    vector<int>vect=arr(nums);
    return vect.size();    
}
int main(){
    vector<int>vect={1,1,1,1,2,2,3,3,3,4,5,5};
    vector<int>expectedNums=arr(vect);
    cout<<removeDuplicates(vect);
    cout<<"----"<<endl;
    for(int i=0;i<expectedNums.size();i++)cout<<expectedNums[i]<<endl;
   // vect.erase(vect.begin()+4);
    //for(int i=0;i<vect.size();i++)cout<<vect[i]<<endl;
}