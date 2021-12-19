class Solution {
public:
    Solution(vector<int>& nums) {

        _nums = nums;
    }

    vector<int> reset() {

        return _nums;
    }
    
    vector<int> shuffle() {

        auto a = _nums;
        int size = _nums.size();
        for (int i = 0; i < size; i++) {
            swap(a[i], a[i + rand() % (size - i)]);
        }
        return a;
    }

private:
    vector<int> _nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
