class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {

        kthLargest = vector<int>();
        if (nums.size() > 0){
            std::sort(nums.begin(), nums.end());
            for (vector<int>::reverse_iterator rit = nums.rbegin();
                 rit < nums.rbegin() + k && rit != nums.rend(); rit++) {
                kthLargest.push_back(*rit);
            }
        }
        for (int i = kthLargest.size(); i < k; i++) {
            kthLargest.push_back(INT_MIN);
        }
    }
    
    int add(int val) {

        int k = kthLargest.size();
        kthLargest.push_back(val);
        for (int i = 0; i < k; i++) {
            if (val >= kthLargest[i]) {
                kthLargest.insert(kthLargest.begin() + i, val);
                break;
            }
        }
        kthLargest.resize(k);
        return kthLargest[k - 1];
    }

private:
    vector<int> kthLargest;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
