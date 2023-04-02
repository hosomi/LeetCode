class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int size = spells.size();
        long long psize = potions.size();
        vector<int> result(size);
        std::sort(begin(potions), end(potions));
        for (int i = 0; i < size; i++) {
			long long val = (success + spells[i] - 1)/(spells[i]*1ll);
            int idx = lower_bound(begin(potions), end(potions), val) - begin(potions);
            result[i] = std::max((int)psize - idx, 0);
        }
        return result;
    }
};
