class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        while (stones.size() > 1) {
            std::sort(stones.begin(), stones.end(), greater<int>());
            int x = stones[0];
            int y = stones[1];
            stones.erase(stones.begin() + 1);
            stones.erase(stones.begin() + 0);
            
            if (x != y) {
                stones.push_back(std::abs(x - y));
            }
        }
        return stones.size() > 0 ? stones[0] : 0;
    }
};
