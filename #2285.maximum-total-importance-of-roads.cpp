class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        map<long long,long long> m;
        for (auto i:roads) {
            for(auto j:i) {
                m[j]++;
            }
        }

        long long result = 0;
        vector<long long> helper;
        for (auto i : m) {
           helper.push_back(i.second);
        }

        std::sort(helper.rbegin(), helper.rend());

        for (auto i : helper) {
            result=result + (n * i);
            n--;
        }
        return result;
    }
};
