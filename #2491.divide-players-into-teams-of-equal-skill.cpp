class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        std::sort(skill.begin(), skill.end());
        
        int n = skill.size();
        long long prod = 0;
        long long sum = skill[0] + skill[n - 1];
        for (int i = 0; i < n / 2; i++) {
            long long currsum = skill[i] + skill[n - i - 1];
            if (currsum != sum) {
                return -1;
            }
            prod += skill[i] * skill[n - i - 1];
        }
        return prod;
    }
};
