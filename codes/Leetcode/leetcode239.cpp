class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> que;
        for (int i = 0; i < k - 1; ++i) {
            que.push(make_pair(nums[i], i));
        }

        vector<int> ans;
        for (int i = k - 1; i < nums.size(); ++i) {
            que.push(make_pair(nums[i], i));

            while (que.top().second + k <= i) {
                que.pop();
            }
            ans.push_back(que.top().first);
        }
        return ans;
    }
};
