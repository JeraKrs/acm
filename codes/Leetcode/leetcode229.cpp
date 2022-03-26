class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int vote1 = 0;
        int vote2 = 0;
        int elem1 = 0;
        int elem2 = 0;
        for (auto& num : nums) {
            if (vote1 && num == elem1) {
                ++vote1;
            } else if (vote2 && num == elem2) {
                ++vote2;
            } else if (vote1 == 0) {
                ++vote1;
                elem1 = num;
            } else if (vote2 == 0) {
                ++vote2;
                elem2 = num;
            } else {
                --vote1;
                --vote2;
            }
        }

        int cnt1 = 0;
        int cnt2 = 0;
        for (auto& num : nums) {
            if (vote1 && num == elem1) {
                ++cnt1;
            }
            if (vote2 && num == elem2) {
                ++cnt2;
            }
        }
        vector<int> ans;
        if (cnt1 > nums.size() / 3) {
            ans.emplace_back(elem1);
        }
        if (cnt2 > nums.size() / 3) {
            ans.emplace_back(elem2);
        }
        return ans;
    }
};
