class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        int size = nums.size();
        if (size % k != 0) {
            return false;
        }

        map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }

        int freq = size / k;
        map<int, int>::iterator it;
        while (freq > 0) {
            it = m.begin();
            int smallest = it->first;
            int second = it->second;
            for (int i = smallest; i < smallest + k; i++) {
                if (m.find(i) != m.end() && m[i] >= second) {
                    m[i]-=second;
                    if (m[i] == 0) {
                        m.erase(i);
                    }
                } else {
                    return false;
                }
            }
            freq -= second;
        }
        return true;
    }
};
