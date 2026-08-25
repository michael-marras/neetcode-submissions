class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> record;

        for (string operation : operations) {
            if (operation == "+") {
                int operand1 = record.top();
                record.pop();
                int operand2 = record.top();
                record.pop();
                record.push(operand2);
                record.push(operand1);
                record.push(operand1 + operand2);
            }
            else if (operation == "D") {
                int operand = record.top();
                int result = operand * 2;
                record.push(result);
            }
            else if (operation == "C") {
                record.pop();
            }
            else{
                record.push(std::stoi(operation));
            }
        }
        
        int ans = 0;
        while (!record.empty()) {
            ans += record.top();
            record.pop();
        }

        return ans;
    }
};