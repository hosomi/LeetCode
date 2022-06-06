class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {

        int size = messages.size();
        unordered_map<string,int> um;
        int count = 0;
        for (int i = 0; i < size; i++) {
            count = 0;
            string s = messages[i];
            for (int j = 0;j<s.size();j++) {
                if (s[j] == ' ') {
                    count++;
                }
            }
            count++;
            um[senders[i]] += count;
        }

        vector<int> counts; 
        for (auto &it : um) {
            counts.push_back(it.second);
        }

        int me = *std::max_element(counts.begin(), counts.end()); 
        vector<string> result;
        for (auto &it : um) {
            if (it.second == me) {
                result.push_back(it.first);
            }
        }

        if (result.size() == 1) {
            return result[0];
        } else{
            return *std::max_element(result.begin(), result.end());
        }
    }
};
