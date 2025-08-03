#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0;
        long long currentSum = 0;
        int maxFruits = 0;

        for (int right = 0; right < n; ++right) {
            currentSum += fruits[right][1];
            
            int leftPos = fruits[left][0];
            int rightPos = fruits[right][0];
            
            long long stepsNeeded = (long long)rightPos - leftPos + std::min(std::abs((long long)startPos - leftPos), std::abs((long long)startPos - rightPos));

            while (stepsNeeded > k) {
                currentSum -= fruits[left][1];
                left++;
                if (left > right) break;
                
                leftPos = fruits[left][0];
                stepsNeeded = (long long)rightPos - leftPos + std::min(std::abs((long long)startPos - leftPos), std::abs((long long)startPos - rightPos));
            }
            
            maxFruits = std::max(maxFruits, (int)currentSum);
        }
        
        return maxFruits;
    }
};