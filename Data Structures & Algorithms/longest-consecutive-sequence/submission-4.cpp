class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        std::set<int> numberSet;
        for (int i = 0; i < nums.size(); i++) {
            numberSet.insert(nums.at(i));
        }

        int counter = 1;
        int longest = 1;
        auto prev = numberSet.begin();
        auto it = std::next(numberSet.begin());
        for (; it != numberSet.end(); it++) {
            if (*it == (*prev) + 1) {
                counter++;
            }
            else {
                counter = 1;
            }

            if (counter > longest) {
                longest = counter;
            }
            prev = it;
        }

        return longest;
    }
};
