class Solution {
public:
    vector<int> minOperations(string boxes) {

        vector<int> results;
        for (int i = 0; i < boxes.size(); i++) {
            int t = 0;
            for (int j = 0; j < boxes.size(); j++) {
                if (boxes[j] == '1') {
                    t += abs(j - i);
                }
            }
            results.push_back(t);
        }
        return results;
    }
};
