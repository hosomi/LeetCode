class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        int derive = 0;
        for (int i = 0; i < derived.size(); i++) {
            derive ^= derived[i];
        }
        return derive == 0;
    }
};
