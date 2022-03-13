class Solution {
public:
    void getVersionNum(const string& version, vector<long long>* nums) {
        long long v = 0;
        for (int i = 0; i < version.size(); ++i) {
            if (version[i] == '.') {
                nums->push_back(v);
                v = 0;
            } else if(version[i] >= '0' && version[i] <= '9') {
                v = v * 10 + version[i] - '0';
            }
        }
        nums->push_back(v);
    }

    int compareVersion(string version1, string version2) {
    
        vector<long long> num1;
        vector<long long> num2;
        getVersionNum(version1, &num1);
        getVersionNum(version2, &num2);

        for (int i = 0; i < num1.size() || i < num2.size(); ++i) {
            long long lhs = 0;
            long long rhs = 0;

            if (i < num1.size()) {
                lhs = num1[i];
            }
            if (i < num2.size()) {
                rhs = num2[i];
            }
            
            if (lhs > rhs) {
                return 1;
            } else if (lhs < rhs) {
                return -1;
            }
        }
        return 0;
    }
};
