class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> indexMap;

        for (int i = 0; i < nums.size(); i++) {
            indexMap[nums.at(i)] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums.at(i);

            if (indexMap.find(difference) != indexMap.end()) {
                if (indexMap.at(difference) != i) {
                    return {i, indexMap.at(difference)};
                }
            }
        }

        return {};
    }
};
