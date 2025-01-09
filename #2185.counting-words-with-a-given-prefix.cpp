class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

		int count = 0;
		for (auto word : words) {
			if (word.find(pref) < 1) { 
				count++;
            }
        }
		return count;
    }
};
