class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequencies;
        for (int num : nums) {
            frequencies[num]++;
        }

        auto cmp = [](std::pair<int, int> a, std::pair<int, int> b) {
            return a.second < b.second;
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> maxHeap(cmp);
        for (auto it = frequencies.begin(); it != frequencies.end(); it++) {
            maxHeap.push(*it);
        }

        std::vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return ans;
    }   
};
