class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {

        int size = changed.size();
        vector<int> result;
        int index = 0;
        for (int i = 0; i < size; i++) {
            if (changed[i] == 0) {
                index++;
            }
        }
        
        if ((index & 1) != 0) {
            return {};
        }

        index /= 2;
        while (index--) {
            result.push_back(0);
        }
        
        std::sort(changed.begin(),changed.end());

        for (int i = 0; i < size; i++) {
            if (changed[i] <= 0) {
                continue;
            }

            int temp = changed[i];
            auto idx = lower_bound(changed.begin(),changed.end(),temp * 2);
            if (idx == changed.end() || *idx != temp*2) {
                return {};
            }

            *idx = -1;
            changed[i] = -1;
            result.push_back(temp);
        }
        return result;
    }
};
