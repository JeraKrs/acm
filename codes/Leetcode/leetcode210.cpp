class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependents;
        vector<vector<int>> successors;
        dependents.resize(numCourses);
        successors.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            dependents[prerequisites[i][0]].push_back(prerequisites[i][1]);
            successors[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> counts;
        counts.resize(numCourses);
        queue<int> que;
        for (int i = 0; i < numCourses; ++i) {
            counts[i] = 0;
            if (dependents[i].size() == 0) {
                que.push(i);
            }
        }

        vector<int> ans;
        while (!que.empty()) {
            int s = que.front();
            que.pop();
            ans.push_back(s);
            for (int i = 0; i < successors[s].size(); ++i) {
                int e = successors[s][i];
                if (dependents[e].size() == counts[e]) {
                    continue;
                }
                if (++counts[e] == dependents[e].size()) {
                    que.push(e);
                }
            }
        }

        if (ans.size() != numCourses) {
            ans.clear();
        }
        return ans;
    }
};
