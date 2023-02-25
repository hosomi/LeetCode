class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int size = deck.size();
        vector<int> v;
        for (int i = 0; i < size; i++) {
            v.push_back(i);
        }
        
        std::sort(deck.begin(), deck.end());
        
        vector<int> result(size);
        for (int i = 0; i < size; i++) {
            result[v.front()] = deck[i];
            v.erase(v.begin());
            if (!v.empty()) {
                v.push_back(v.front());
                v.erase(v.begin());
            }
        }
        return result;
    }
};
