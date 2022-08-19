class Solution {
public:
    bool isPossible(vector<int>& nums) {

        vector<int> tails;
        vector<int>::iterator it;
        while (!nums.empty()) {
            int head = nums[0]; 
            if (tails.size() == 0
                || (it = std::upper_bound(tails.begin(), tails.end(), head-1)) == tails.begin()
                || (*(it = prev(it)) != head-1)) {

                nums.erase(nums.begin());
                it = std::find(nums.begin(), nums.end(), head + 1);
                if (it == nums.end()) {
                    return false;
                }

                nums.erase(it);
                it = std::find(nums.begin(), nums.end(), head + 2);
                if (it == nums.end()) {
                    return false;
                }

                nums.erase(it);
                tails.push_back(head+2);
            } else {
                *it = head;
                it = std::find(nums.begin(), nums.end(), head);
                if (it == nums.end()) {
                    return false;
                }
                
                nums.erase(it);
            }
        }        
        return true;
    }
};
