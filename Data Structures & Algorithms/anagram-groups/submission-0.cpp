class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> sortedToGroup;
        for (string s : strs) {
            string sSorted = s;
            std::sort(sSorted.begin(), sSorted.end());
            sortedToGroup[sSorted].push_back(s);
        }

        std::vector<std::vector<string>> ans;
        for (auto &it : sortedToGroup) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
