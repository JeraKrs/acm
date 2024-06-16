  class Solution {
public:
    struct Team {
        Team (int speed, int efficiency) : speed(speed), efficiency(efficiency) {}
        bool operator<(const Team& rhs) {
            if (efficiency == rhs.efficiency) {
                return speed > rhs.speed;
            }
            return efficiency > rhs.efficiency;
        }
        int speed;
        int efficiency;
    };
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        std::vector<Team> teams;
        for (int i = 0; i < n; ++i) {
            teams.emplace_back(Team(speed[i], efficiency[i]));
        }
        sort(teams.begin(), teams.end());

        long long ans = 0;
        long long sum = 0;
        std::priority_queue<long long, std::vector<long long>, std::greater<long long> > que;
        for (int i = 0; i < n; ++i) {
            if (que.size() < k) {
                sum += teams[i].speed;
                que.push(teams[i].speed);
            } else if (teams[i].speed > que.top()) {
                int out = que.top();
                que.pop();
                que.push(teams[i].speed);
                sum += teams[i].speed - out;
            }
            ans = std::max(ans, sum * teams[i].efficiency);
        }
        const int mod = 1e9 + 7;
        return ans % mod;
    }
};
