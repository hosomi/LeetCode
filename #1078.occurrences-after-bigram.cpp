class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {

        vector<string> split = this->split(text, " ");
        vector<string> result;
        for (int i = 0; i < split.size() - 1; i++) {
            if (split[i] == first && split[i+1] == second && i+2 < split.size()) {
                result.push_back(split[i+2]);
            }
        }
        return result;
    }

private:
    vector<std::string> split(std::string str, std::string delimiter) {

        size_t pos = 0;
        string token;
        vector<string> result;
        while ((pos = str.find(delimiter)) != string::npos) {
            token = str.substr(0, pos);
            result.push_back(token);
            str.erase(0, pos + delimiter.length());
        }
        result.push_back(str);
        return result;
    }
};
