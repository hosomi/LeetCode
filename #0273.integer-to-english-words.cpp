class Solution {
public:
    string numberToWords(int num) {

        vector<string> units = {
            "", " Thousand", " Million", " Billion"
        };

        int i = 0;
        string result;
        int remainder;
        while (num) {
            remainder = num % 1000;
            if (remainder) {
                result = numberWords(remainder) + units[i] + result;
            }
            i++;
            num /= 1000;
        }
        return result.length() ? result.substr(1) : "Zero";
    }

private:
    string numberWords(int num) {

        char* ones[] = {
            "", " One", " Two", " Three", " Four", " Five",
            " Six", " Seven", " Eight", " Nine"
        };
        char* tens[] = {
            " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen",
            " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"
        };
        char* tenUnits[] = {
            "", "", " Twenty", " Thirty", " Forty", " Fifty",
            " Sixty", " Seventy", " Eighty", " Ninety"
        };

        string result;
        if (num > 99) {
            result += string(ones[num / 100]) + " Hundred";
        }

        num %= 100;
        if (num > 9 && num < 20) {
            result += tens[num % 10];
        } else {
            if (num > 19) {
                result += tenUnits[num / 10];
            }
            num %= 10;
            if (num) {
                result += ones[num];
            }
        }
        return result;
    }
};
