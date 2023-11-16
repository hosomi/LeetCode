class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        int size = nums[0].size();
        int index = 0;
        string result = "";
        for(int i = 0; i < size; i++, index++) {
            if (nums[i][index] == '0') {
                result.push_back('1');
            } else {
                result.push_back('0');
            }
        }
        return result;
    }
};
