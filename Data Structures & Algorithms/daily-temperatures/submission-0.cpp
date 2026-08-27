class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int max = temperatures[0];
        std::vector<int> ans(temperatures.size(), 0);
        std::stack<int> history;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!history.empty() && temperatures[i] > temperatures[history.top()]) {
                ans[history.top()] = i - history.top();
                history.pop();
            }
            history.push(i);
        }

        return ans;
    }
};
