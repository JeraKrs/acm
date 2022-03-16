class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            while (l < r && numbers[l] + numbers[r] > target) {
                --r;
            }
            if (numbers[l] + numbers[r] == target) {
                break;
            }
            ++l;
        }
        vector<int> ans;
        ans.push_back(l + 1);
        ans.push_back(r + 1);
        return ans;
    }
};
