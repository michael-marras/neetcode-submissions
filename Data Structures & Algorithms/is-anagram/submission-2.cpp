class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::unordered_map<char, int> sCharCount;
        std::unordered_map<char, int> tCharCount;
        for (int i = 0; i < s.size(); i++) {
            sCharCount[s[i]]++;
            tCharCount[t[i]]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (sCharCount[s[i]] != tCharCount[s[i]]) {
                return false;
            }
        }
        
        return true;
    }
};
