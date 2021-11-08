class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        int size = nums.size();
        vector<int> v(nums);
        std::sort(v.begin(), v.end());
        int i = size / 2;
        int j = size - 1;
        if(size % 2 == 0) {
            i--;
        }
        for (int index = 0; index < size; index++) {
            nums[index] = index % 2 == 0 ? v[i--] : v[j--];
        }
    }
};
