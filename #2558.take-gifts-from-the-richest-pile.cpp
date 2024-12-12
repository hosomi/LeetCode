class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        multiset<int, std::greater<int>> sets;
        for (auto gift : gifts) {
            sets.insert(gift);
        }

        while (k) {
            int temp = std::sqrt(*sets.begin());
            sets.erase(sets.begin());
            sets.insert(temp);
            k--;
        }

        long long result = 0;
        for (auto set : sets) {
            result += set;
        }
        return result;
    }
};
