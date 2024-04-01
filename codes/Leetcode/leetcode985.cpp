class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even_num_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & 1) continue;
            even_num_sum += nums[i];
        }

        std::vector<int> ans;
        for (int i = 0; i < queries.size(); ++i) {
            int value = queries[i][0];
            int index = queries[i][1];
            if ((nums[index] & 1) == 0) even_num_sum -= nums[index];

            nums[index] += value;
            if ((nums[index] & 1) == 0) even_num_sum += nums[index];
            ans.emplace_back(even_num_sum);
        }
        return ans;
    }
};
