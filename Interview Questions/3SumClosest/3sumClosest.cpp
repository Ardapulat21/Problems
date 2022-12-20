#include <iostream>
#include <vector>
using namespace std;
int gap(int t,int r){
    if(t*r<0){
        if(r<0)
            return (-1*r)+t;
        else
            return (-1*t)+r;
    }
    else{
        if((r-t)<0)
            return -1*(r-t);
        else
            return r-t;
    }
    return 1;
}
int threeSumClosest(vector<int> nums,int target){
    int first=0;int second=first+1;int third=second+1;
    int sum=(nums[first]+nums[second]+nums[third]);
    int result=gap(target,sum);
    while(first<nums.size()-2){
        cout<<"Result: "<<result<<endl;
        cout<<"First:"<<first<<endl;
        cout<<"Second:"<<second<<endl;
        cout<<"third:"<<third<<endl;
        sum=(nums[first]+nums[second]+nums[third]);
        if(result<gap(target,sum))
            result=gap(target,sum);
        if((third!=nums.size()-1)&& (second!=nums.size()-2)){
            third++;
        }
        else if((third==nums.size()-1)&& (second!=nums.size()-2)){
            second++;
            third=second+1;
        }
        if((second==nums.size()-2)&&(first!=nums.size()-3)){
            first++;
            second=first+1;
        }

    }
                
            
        
     
    return result;
}
int main(){
    vector<int> nums={-1,2,1,-4};
    cout<<threeSumClosest(nums,1);
}