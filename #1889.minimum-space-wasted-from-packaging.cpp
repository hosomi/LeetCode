class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {

        std::sort(packages.begin(), packages.end());
        int size = packages.size();
        long minTotalBoxSize = LONG_MAX;
        for (auto& boxSizes : boxes) {
            std::sort(boxSizes.begin(), boxSizes.end());
            if (boxSizes[boxSizes.size() - 1] < packages[size-1]) {
                continue;
            }

            long totalBoxSize = 0; 
            int startIdx = 0;
            for (int& boxSize : boxSizes) {
                int idx = std::upper_bound(packages.begin() + startIdx, packages.end(), boxSize) - packages.begin() - 1;
                long packedCount = (idx - startIdx + 1); 
                totalBoxSize += packedCount * boxSize;
                startIdx = idx + 1;
            }

            minTotalBoxSize = std::min(minTotalBoxSize, totalBoxSize);
        }

        if (minTotalBoxSize == LONG_MAX) {
            return -1;
        }

        long totalPackageSize = accumulate(packages.begin(), packages.end(), 0L);
        return (minTotalBoxSize - totalPackageSize) % 1000000007;
    }
};
