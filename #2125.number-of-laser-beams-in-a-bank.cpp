class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        int prev = 0;
        int result = 0;
        for (auto i : bank) {
            int count = std::count(begin(i),end(i),'1');
            if (count) {
                result = prev * count + result;
                prev = count;
            }
        }
        return result;
    }
};
