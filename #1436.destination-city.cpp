class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

		unordered_map<string, int> m;
		for (auto p : paths) {
			m[p[0]]++;    
		}

		for (auto p : paths) {
			if (m.find(p[1]) == m.end()) {
				return p[1];
			}
		}
		return "";
    }
};
