class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        vector<int> temp = nums;
        std::sort(temp.begin(),temp.end());
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        map<int, int> mi;
        int count = 1;
        m[count].push(temp[0]);
        mi[temp[0]] = count;
        for (int i = 1; i < size(temp); i++) {
            if (temp[i] - temp[i - 1] <= limit) {
                m[count].push(temp[i]);
                mi[temp[i]] = count;
            } else {
                count++;
                m[count].push(temp[i]);
                mi[temp[i]] = count;
            }
        }
        
        for (int i = 0; i < size(nums); i++) {
            int pos = mi[nums[i]];
            int ele = m[pos].top();
            m[pos].pop();
            
            nums[i] = ele;
        }
        return nums;
    }
};
