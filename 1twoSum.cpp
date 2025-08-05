#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> map;

        for(int i=0; i<nums.size(); i++) {
            int complement = target - nums[i];
            if(map.count(complement)) {
                return{map[complement],i};
            }
            map[nums[i]] = i;
        }
        return{};
        }
};

int main() {
    Solution sol;
    vector<int> nums={1,3,4,5,7,8};
    int test = 9;

    vector<int> testArr =sol.twoSum(nums,test);

    if(testArr.empty()) {
        cout<<"No two numbers were found"<<endl<<"End of the program!"<<endl;
    }else{
        cout<<"Two numbers that add up to "<<test<< " are "<<nums[testArr[0]]<<" and " <<nums[testArr[1]]<<endl;
    }
    return 0;
}