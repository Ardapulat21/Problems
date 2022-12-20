#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    int first=0;int second=first+1;int third=second+1;
    vector<vector<int>> vect;
    vector<int> temp;    
    while(first<nums.size()-2){// iç içe 3 tane for döngüsüyle de yapabilirim. I can do it through 3 for loop.
        
        if(nums[first]+nums[second]+nums[third]==0){
            cout<<"First:"<<first<<endl;
            cout<<"Second:"<<second<<endl;
            cout<<"Third:"<<third<<endl;
            temp.push_back(nums[first]);
            temp.push_back(nums[second]);
            temp.push_back(nums[third]);
            vect.push_back(temp);
            temp.clear();
        }
        if(third<nums.size())
            third++;        
        else{
            second++;
            third=second+1;
        }
        if(second==nums.size()-2){
            first++;
            second=first+1;
        }
    }
    return vect;
}
int main(){
    vector <int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> vect=threeSum(nums);
    for(int i=0;i<vect.size();i++){
        cout<<"-----------"<<endl;
        for(int a=0;a<vect[i].size();a++){
            cout<<vect[i][a]<<endl;
        }  
        cout<<"------------"<<endl;      
    }      
}