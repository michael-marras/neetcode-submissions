class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        int res = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums.at(i);
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                res += prefixSumCount.at(sum - k);
            }
            prefixSumCount[sum]++;
        }

        return res;
     }
};