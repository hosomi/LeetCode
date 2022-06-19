class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

        auto it = products.begin();
        std::sort(it, products.end());        
        string cursor = "";
        vector<vector<string>> result;
        for (char c : searchWord) {
            cursor += c;
            vector<string> suggested;
            it = lower_bound(it, products.end(), cursor);
            for (int i = 0; i < 3 && it + i != products.end(); i++) {
                string& s = *(it + i);
                if (s.find(cursor) != 0) {
                    break;
                }
                suggested.push_back(s);
            }
            result.push_back(suggested);
        }
        return result;
    }
};
