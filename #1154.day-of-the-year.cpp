class Solution {
public:
    int dayOfYear(string date) {
        vector<string> v = split(date, "-");
        vector<int> vy;
        int output;
        
        std::transform(
            v.begin(),
            v.end(),
            std::back_inserter(vy),
            [](const std::string& s) { 
                return std::stoi(s);
            }
        );
        
        output = vy[2];
        
        for (int m = 1; m < vy[1]; m++) {
            if (m == 2) {
                output += 28;
                if (vy[0] % 400 == 0) {
                    output += 1;
                } else if(vy[0] % 100 == 0) {
                    ;
                } else if(vy[0] % 4 == 0) {
                    output += 1;
                }
            } else if (m < 8) {
                if (m % 2 == 1) {
                    output += 31;
                } else {
                    output += 30;
                }
            } else {
                if (m % 2 == 1) {
                    output += 30;
                } else {
                    output += 31;
                }
            }
        }
        
        return output;
    }
    
    std::vector<std::string> split(std::string str, std::string delimiter) {

        size_t pos = 0;
        std::string token;
        std::vector<std::string> result;

        while ((pos = str.find(delimiter)) != std::string::npos) {
            token = str.substr(0, pos);
            result.push_back(token);
            str.erase(0, pos + delimiter.length());
        }

        result.push_back(str);
        return result;
    }
};

