//One hash table approace (others: Brute force, two-hash table)
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        std::unordered_map<int, int> numToIndexMap; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (numToIndexMap.find(diff) != numToIndexMap.end()) {
                return {numToIndexMap[diff], i}; // return the index of diff and current index
            }

            numToIndexMap[nums[i]] = i; // store current number and its index
        }

        return {}; // in case no solution found
    }
};
