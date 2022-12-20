#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector <int> arr;
    int result=0;
    double result1=0;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        result=0;
        result1=0;
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());

        if(nums1.size()%2==0){// 1,2,3,4
            result1=double(nums1[nums1.size()/2-1]+nums1[nums1.size()/2])/2;
            cout<<"result: "<<result1<<endl;
        }
        else{//1,2,3,4,5
            result=nums1[nums1.size()/2];
            cout<<"result: "<<result<<endl;
        }
    }
};

int main()
{   Solution* s=new Solution();
    vector<int> arr1={1,2};
    vector<int> arr2={3,4};

    s->findMedianSortedArrays(arr1,arr2);
    return 0;
}
