class Solution {
private:
    string trim(const string &str, size_t start= 0){
                if(start >= str.size() || str[start] != ' '){
                    return str.substr(start);
                }
                return trim(str, start + 1);
            }
    pair<int, string>  detect_sign(const string &str, size_t start = 0){
            if (start >= str.size()){
                return {1, str};
            }
            if ( str[start] == '+'){
                return {1, str.substr(start+1)};
            }
            if ( str[start] == '-'){
                return {-1, str.substr(start+1)};
            }
            return {1, str};
        }
    string extract_digits(const string &str, size_t start = 0){
            if(start >= str.size() || !isdigit(str[start])){
                return "";
            }
            return str[start] + extract_digits(str, start + 1);
        }
    int myAtoiHelper(string s){
            s = trim(s);
            auto [sign, remaining_str] = detect_sign(s);
            string digits_str = extract_digits(remaining_str);

            long long result = 0;
            for (char c : digits_str){
                result = result * 10 + (c-'0');

                if (result > INT_MAX){
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
            }

            return static_cast<int>(result)* sign;
        }

public:
    int myAtoi(string s) {
        return myAtoiHelper(s);
        };
};