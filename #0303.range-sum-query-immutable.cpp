class NumArray {
public:
    NumArray(vector<int>& nums) {

        this->nums = nums;
    }

    int sumRange(int left, int right) {

        int result = 0;
        for (int i = left; i <= right; i++) {
            result += nums[i];
        }
        return result;
    }

private:
     vector<int> nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
