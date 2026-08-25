class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedS;
        for (string s : strs) {
            encodedS.append(to_string(s.size()));
            encodedS.push_back('#');
            for (char c : s) {
                encodedS.push_back(c);
            }
        }
        encodedS.push_back('!');

        return encodedS;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int counter = 0;
        string currSub;
        while (s.at(counter) != '!') {
            while (s.at(counter) != '#') {
                currSub.push_back(s.at(counter));
                counter++;
            }

            int substrLen = std::stoi(currSub);
            currSub.clear();
            counter += 1;
            int temp = counter;
            for (int i = 0; i < substrLen; i++) {
                currSub.push_back(s.at(temp + i));
                counter++;
            }
            ans.push_back(currSub);
            currSub.clear();
        }
        return ans;
    }
};
