#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> result;
        int start=0;
        int endd=numbers.size()-1;
        int sum=0;
        while(start<=endd){
            cout<<"sad"<<endl;
            sum=numbers[start]+numbers[endd];
            if(sum<target){
                start++;
            }
            else if(sum>target){
                endd--;
            }
            else{
                result.push_back(start+1);
                result.push_back(endd+1);
                return result;
            }
        }
        return result;
    }
};

int main()
{
    vector <int> v={2,7,11,15};
    Solution* s=new Solution();
    v=s->twoSum(v,9);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}
