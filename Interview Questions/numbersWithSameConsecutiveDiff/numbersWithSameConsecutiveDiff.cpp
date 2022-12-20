#include <iostream>
#include <vector>
#include <algorithm>    
using namespace std;
bool isEqual(vector<int> nums,int k){
    for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]){
                if(nums[i+1]-nums[i]!=k){                
                    return false;
                }  
            }else{
                if(nums[i+1]-nums[i]!=-k){                
                    return false;
                }
            }
                  
        }
    return true;
}
vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> nums;
    vector<int> arr;
    int bborder=1;int tborder=10;
    for(int i=0;i<n-1;i++){
        bborder*=10;
        tborder*=10;
    }
    int number=bborder;
    int temp;int index;
    while(bborder<tborder){             
        temp=bborder;        
        for(int i=0;i<n;i++){            
            nums.push_back(temp%10);
            temp/=10;
        }               
        if(isEqual(nums,k)){
            cout<<"Bborder: "<<bborder<<endl;
            arr.push_back(bborder);
        }
        
        // burada rakamları nums vectorune ekledim.        
        bborder++;
        nums.clear();
    }     
    return arr;   
}
int main(){
    vector<int>vect=numsSameConsecDiff(3,7);
    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<endl;
    }
}