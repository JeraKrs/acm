class Solution {
public:
    std::string replace(std::string str, char from, char to) {
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == from) str[i] = to;
        }
        return str;
    }
    int to_num(std::string str) {
        int num = 0;
        for (int i = 0; i < str.size(); ++i) {
            num = num * 10 + str[i] - '0';
        }
        return num;
    }
    int maxDiff(int num) {
        std::string num_str = std::to_string(num);
        std::string max_str = num_str, min_str = num_str;
        for (int i = 0; i < num_str.size(); ++i) {
            if (num_str[i] !='9') {
                max_str = replace(num_str, num_str[i], '9');
                break;
            }
        }
        for (int i = 0; i < num_str.size(); ++i) {
            if (i == 0 && num_str[i] != '1') {
                min_str = replace(num_str, num_str[i], '1');
                break;
            }
            if (num_str[i] != '0' && num_str[i] != num_str[0]) {
                min_str = replace(num_str, num_str[i], '0');
                break;
            }
        }
        return to_num(max_str) - to_num(min_str);
    }
};
