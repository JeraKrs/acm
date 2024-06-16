class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());

        int ans = 0, mov = 0;
        for (int i = people.size() - 1; i >= mov; --i) {
            if (i != mov && people[i] + people[mov] <= limit) ++mov;
            ++ans;
        }
        return ans;
    }
};
