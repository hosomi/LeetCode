class Solution {
public:
    vector<int> pathInZigZagTree(int label) {

        int level = int(std::log2(label));
        vector<int> path;
        int node;
        int index;
        path.push_back(label);
        node = label;
        while (node != 1) {
            if (level % 2 == 0) {
                index = node - std::pow(2, level);
                index /= 2;
                node = (std::pow(2, level) - 1) - index;
            } else {
                index = (std::pow(2, level) - 1) - (node - std::pow(2, level));
                index /= 2;
                node = std::pow(2, level - 1) + index;
            }
            path.insert(path.begin(), node);
            level--;
        };
        return path;
    }
};
