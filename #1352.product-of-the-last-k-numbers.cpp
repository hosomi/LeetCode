class ProductOfNumbers {
public:
    ProductOfNumbers() {

        nums.push_back(1);
    }

    void add(int num) {

        if (num != 0) {
            nums.push_back(num * nums.back());
            return;
        }
        nums.clear();
        nums.push_back(1);
    }

    int getProduct(int k) {

        if (nums.size() > k) {
            return nums.back() / nums[nums.size() - k - 1];
        }

        return 0;
    }

private:
    vector<int> nums;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
