class Solution {
public:

    string reformatDate(string date) {

        vector<string> vmonth = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        vector<string> vsplit = split(date);
        string strmonth = to_string(find(vmonth.begin(), vmonth.end(), vsplit[1]) - vmonth.begin() + 1);
        if(strmonth.size() == 1) {
            strmonth = "0" + strmonth;
        }
        
        string strday = vsplit[0].substr(0, vsplit[0].size() -2);
        if(strday.size() == 1) {
            strday = "0" + strday;
        }
        
        return vsplit[2] + "-" + strmonth + "-" + strday;
    }
    
    std::vector<std::string> split(std::string date)
    {  
        std::istringstream ss(date);
        std::vector<std::string> result;
        std::string word;

        while (ss >> word) {
            result.push_back(word);
        }

        return result;
    }
};
