class MinStack {
    public:
        MinStack() {
            
        }

        void push(int val) {
            _history.push(val);
            if (val < _min || _minHistory.empty()) {
                _min = val;
            }

            _minHistory.push(_min);
        }

        void pop() {
            _history.pop();
            _minHistory.pop();
            if (!_minHistory.empty())_min = _minHistory.top();
        }

        int top() {
            return _history.top();
        }

        int getMin() {
            return _minHistory.top();
        }

    private:
        std::stack<int> _history;
        std::stack<int> _minHistory;
        int _min = 0;
};
