class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        std::sort(arr.begin(), arr.end());
        multimap<int, int> mp;
        for (auto a : arr) {
            mp.emplace(make_pair(__builtin_popcount(a), a));
        }

        arr.clear();
        for (auto m : mp) {
            arr.push_back(m.second);
        }
        return arr;
    }
};
