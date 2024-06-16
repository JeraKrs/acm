class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        std::set<std::vector<int> > records;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            std::vector<int> arr;
            
            for (int j = i; j < n; ++j) {
                if (nums[j] % p == 0) ++cnt;
                if (cnt > k) break;

                arr.emplace_back(nums[j]);
                records.insert(arr);
            }
        }
        return records.size();
    }
};
