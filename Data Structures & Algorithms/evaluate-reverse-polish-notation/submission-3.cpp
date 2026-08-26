class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> history;

        for (string token : tokens) {
            if (token == "+") {
                if (history.empty()) return -1;
                int operand1 = history.top();
                history.pop();
                if (history.empty()) return -1;
                int operand2 = history.top();
                history.pop();
                history.push(operand1 + operand2);
            }
            else if (token == "-") {
                if (history.empty()) return -1;
                int operand1 = history.top();
                history.pop();
                if (history.empty()) return -1;
                int operand2 = history.top();
                history.pop();
                history.push(operand2 - operand1);
            }
            else if (token == "*") {
                if (history.empty()) return -1;
                int operand1 = history.top();
                history.pop();
                if (history.empty()) return -1;
                int operand2 = history.top();
                history.pop();
                history.push(operand1 * operand2);
            }
            else if (token == "/") {
                if (history.empty()) return -1;
                int operand1 = history.top();
                history.pop();
                if (history.empty()) return -1;
                int operand2 = history.top();
                history.pop();
                history.push(operand2 / operand1);
            }
            else {
                history.push(std::stoi(token));
            }

        }

        return history.empty() ? -1 : history.top();
    }
};
