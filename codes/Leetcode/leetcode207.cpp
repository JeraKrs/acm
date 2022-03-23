class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int numExecute = 0;
        while (!que.empty()) {
            int s = que.front();
            que.pop();
            ++numExecute;
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
        return numExecute == numCourses;
    }
};
