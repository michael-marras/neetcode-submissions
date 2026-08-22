class NumArray {
public:
    NumArray(vector<int>& nums) {
        _nums = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++){
            sum+=_nums.at(i);
        }

        return sum;
    }

private: 
    std::vector<int> _nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */