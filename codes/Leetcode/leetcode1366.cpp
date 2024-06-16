class Solution {
public:
    struct Team {
        char name;
        int rank[26];
    };
    static bool cmp(const Team& lhs, const Team& rhs) {
        for (int i = 0; i < 26; ++i) {
            if (lhs.rank[i] != rhs.rank[i]) {
                return lhs.rank[i] > rhs.rank[i];
            }
        }
        return lhs.name < rhs.name;
    }
    string rankTeams(vector<string>& votes) {
        std::vector<Team> teams;
        teams.resize(26);
        for (int i = 0; i < 26; ++i) {
            teams[i].name = 'A' + i;
            memset(teams[i].rank, 0, sizeof(teams[i].rank));
        }
    
        for (int i = 0; i < votes.size(); ++i) {
            for (int j = 0; j < votes[i].size(); ++j) {
                int vote = votes[i][j] - 'A';
                teams[vote].rank[j]++;
            }
        }

        std::sort(teams.begin(), teams.end(), cmp);

        int n = votes[0].size();
        std::string ans = "";
        for (int i = 0; i < n; ++i) {
            ans += teams[i].name;
        }
        return ans;
    }
};
