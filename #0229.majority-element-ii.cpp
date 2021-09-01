class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }

        vector<int> result;
        int moretime = nums.size() / 3;
        for (auto a = counter.begin(); a != counter.end(); a++) { 
            if (a->second > moretime) {
                result.push_back(a->first);
            }
        }
        return result;
    }
};
