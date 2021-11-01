class NumArray {
public:
    NumArray(vector<int>& nums) {

        data = nums;
        if (nums.empty()) {
            return;
        }

        int size = nums.size();
        bit = vector<int>(size + 1, 0);
        for (int i = 1; i <= size; i++) {
            int index = i;
            while (index <= size) {
                bit[index] += nums[i - 1];
                index = index + (index&(~(index - 1)));
            }
        }
    }

    void update(int index, int val) {

        int diff = val - data[index];
        data[index] = val;
        int i = index+1;
        while (i <= data.size()) {
            bit[i] += diff;
            i = i+(i&(~(i-1)));
        }
    }

    int sumRange(int left, int right) {

        if (left == 0) {
            return sumSub(right);
        }
        return sumSub(right) - sumSub(left-1);
    }

private:
    vector<int> bit, data;
    int sumSub(int i){
        int k=i+1,res=0;
        while(k){
            res+=bit[k];
            k=k&(k-1);
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
