class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        multiset<int> ms;
        for (int h: hand) {
            ms.insert(h);
        }

        while (ms.size()) {
            int start = *ms.begin();
            for (int i = 0; i < groupSize; ++i) {
                auto it = ms.find(start + i);
                if (it == ms.end()) {
                    return false;
                }

                ms.erase(it);
            }
        }

        return true;
    }
};
