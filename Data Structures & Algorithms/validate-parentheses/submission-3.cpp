class Solution {
public:
    bool isValid(string s) {
        std::stack<char> history;

        for (char x : s) {
            if (x == '(' || x == '[' || x == '{') {
                history.push(x);
            }
            else if (history.empty()) {
                return false;
            }
            else if (x == ')') {
                if (history.top() != '(') {
                    return false;
                }
                else {
                    history.pop();
                }
            }
            else if (x == ']') {
                if (history.top() != '[') {
                    return false;
                }
                else {
                    history.pop();
                }
            }
            else if (x == '}') {
                if (history.top() != '{') {
                    return false;
                }
                else {
                    history.pop();
                }
            }
        }

        return history.empty() ? true: false;
    }
};
