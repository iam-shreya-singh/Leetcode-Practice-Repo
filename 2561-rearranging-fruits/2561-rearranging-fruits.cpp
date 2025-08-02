class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

 std::unordered_map<int, int> totalCounts;
        for (int fruit : basket1) {
            totalCounts[fruit]++;
        }
        for (int fruit : basket2) {
            totalCounts[fruit]++;
        }

        long long minOverallCost = -1;

        for (auto const& [fruit, count] : totalCounts) {
            if (count % 2 != 0) {
                return -1;
            }
            if (minOverallCost == -1 || fruit < minOverallCost) {
                minOverallCost = fruit;
            }
        }

        std::unordered_map<int, int> basket1Counts;
        for (int fruit : basket1) {
            basket1Counts[fruit]++;
        }
        
        std::vector<long long> surplus1;
        std::vector<long long> surplus2;

        for (auto const& [fruit, total_count] : totalCounts) {
            int targetCount = total_count / 2;
            int b1Count = basket1Counts.count(fruit) ? basket1Counts[fruit] : 0;
            
            if (b1Count > targetCount) {
                int numToSwap = b1Count - targetCount;
                for (int i = 0; i < numToSwap; ++i) {
                    surplus1.push_back(fruit);
                }
            } else if (b1Count < targetCount) {
                int numToSwap = targetCount - b1Count;
                for (int i = 0; i < numToSwap; ++i) {
                    surplus2.push_back(fruit);
                }
            }
        }
        
        std::sort(surplus1.begin(), surplus1.end());
        std::sort(surplus2.begin(), surplus2.end(), std::greater<long long>());

        long long totalMinCost = 0;
        for (size_t i = 0; i < surplus1.size(); ++i) {
            long long fruitFrom1 = surplus1[i];
            long long fruitFrom2 = surplus2[i];

            long long directSwapCost = std::min(fruitFrom1, fruitFrom2);
            long long indirectSwapCost = 2 * minOverallCost;

            totalMinCost += std::min(directSwapCost, indirectSwapCost);
        }

        return totalMinCost;
    }
};