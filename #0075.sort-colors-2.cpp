class Solution {
public:
    void sortColors(vector<int>& nums) {

        map<int, int> mcounter;
        for (int& num : nums) {
            mcounter[num]++;
        }
        
        int index = 0;
        for (auto counter = mcounter.begin(); counter != mcounter.end(); counter++) {
            while(counter->second) {
                nums[index++] = counter->first;
                counter->second--;
            }
        }
    }
};
