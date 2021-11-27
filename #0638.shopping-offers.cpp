class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {

        int shoppingOffer = INT_MAX;
        for (const auto& s : special) {
            vector<int> v(needs);
            bool isOffer = true;
            for (int i = 0; i < price.size(); ++i) {
                if (!(isOffer &= ((v[i] -= s[i]) >= 0))) {
                    break;
                }
            }
            if (!isOffer) {
                continue;
            }
            shoppingOffer = std::min(shoppingOffer, shoppingOffers(price, special, v) + s.back());
        }
        int inner = inner_product(begin(price), end(price), begin(needs), 0);
        return std::min(shoppingOffer, inner);
    }
};
