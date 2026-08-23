class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> prefixes;
        for (int i = 0; i < nums.size(); i++) {
            product = product * nums.at(i);
            prefixes.push_back(product);
        }

        product = 1;
        std::unordered_map<int, int> suffixes;
        for (int i = nums.size() - 1; i >= 0; i--) {
            product = product * nums.at(i);
            suffixes[i] = product;
        }

        vector<int> ans; 
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                ans.push_back(suffixes.at(i + 1));
            }
            else if (i == nums.size() - 1) {
                ans.push_back(prefixes.at(i - 1));
            }
            else {
                ans.push_back(prefixes.at(i - 1) * suffixes.at(i + 1));
            }
        }

        return ans;
    }
};
