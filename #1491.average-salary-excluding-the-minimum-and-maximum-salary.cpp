class Solution {
public:
    double average(vector<int>& salary) {
        
        int size = salary.size();
        int sum = std::accumulate(salary.begin(), salary.end(), 0);
        int max = *std::max_element(salary.begin(), salary.end());
        int min = *std::min_element(salary.begin(), salary.end());
        return (sum - max - min) / (double)(size - 2);
    }
};
