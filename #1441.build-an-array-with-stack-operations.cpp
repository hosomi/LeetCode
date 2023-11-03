class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        int size = target.size();
        int index = 0;
        vector<string> results;
        for (int i = 1; i <= n; i++) {
            if (index == size) {
                break;
            }

            if (i == target[index]) {
                results.push_back("Push");
                index++;
            } else {
                results.push_back("Push");
                results.push_back("Pop");
            }
            
        }
        return results;
    }
};
