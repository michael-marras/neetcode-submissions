class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> numCount;
        for (int num : nums) {
            numCount[num]++;
            if (numCount[num] > 1) {
                return true;
            }
        }

        return false;
    }
};