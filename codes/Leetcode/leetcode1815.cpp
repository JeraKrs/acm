class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        std::vector<int> cnt(batchSize);
        for (auto g : groups) {
            ++cnt[g % batchSize];
        }

        long long start = 0;
        for (int i = batchSize - 1; i; --i) {
            start = (start << bitWidth) | cnt[i];
        }

        std::map<long long, int> memory;
        std::function<int(long long)> dfs = [&](long long s) {
            if (s == 0) return 0;

            if (memory.find(s) != memory.end()) {
                return memory[s];
            }

            int sum = 0;
            for (int i = 1; i < batchSize; ++i) {
                int count = (s >> ((i-1) * bitWidth)) & bitMask;
                sum += i * count;
            }

            int ans = 0;
            for (int i = 1; i < batchSize; ++i) {
                int count = (s >> ((i-1) * bitWidth)) & bitMask;
                if (count) {
                    int result = dfs(s - (1LL << ((i-1) * bitWidth)));
                    if ((sum - i) % batchSize == 0) {
                        ++result;
                    }
                    ans = std::max(ans, result);
                }
            }
            return memory[s] = ans;
        };
        
        return dfs(start) + cnt[0];
    }
private:
    static constexpr int bitWidth = 5;
    static constexpr int bitMask = (1<<bitWidth) - 1;
};
