class Solution {
public:
    bool checkPowersOfThree(int n) {
        
        return n ? n % 3 != 2 && checkPowersOfThree(n / 3) : true;
    }
};
