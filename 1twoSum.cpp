#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> map;

        for(int i=0; i<nums.size(); i++) {
                    //Key,Value
            

            int oppVal = target - nums[i];

            if(map.count(oppVal)){
                return {i,map[oppVal]};
            }
            map.insert({nums[i],i});
        }

        return{};
    }
