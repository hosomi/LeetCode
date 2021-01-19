class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

    	int size = nums.size();
        int index = 0;
        vector<int> vresult(size);
        vector<int> vcounter(100001);
        for (int num : nums) {
            ++vcounter[num + 50000];
        }

        for (int i = 0; i < vcounter.size(); ++i) {
        	while (vcounter[i]-- > 0) {
        		vresult[index++] = i - 50000;
        	}
        }
        return vresult;
    }
};
