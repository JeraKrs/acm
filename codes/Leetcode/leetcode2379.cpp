class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        std::vector<int> blacks;
        blacks.resize(blocks.size() + 1, 0);
        int sum = 0;
        for (int i = 1; i <= blocks.size(); ++i) {
            if (blocks[i-1] == 'B') {
                blacks[i] = blacks[i-1] + 1;
            } else {
                blacks[i] = blacks[i-1];
            }
            printf("%d %d\n", i, blacks[i]);
        }

        int ans = k;
        for (int i = 0; i + k <= blocks.size(); ++i) {
            ans = std::min(ans, k - (blacks[i+k] - blacks[i]));
        }
        return ans;
    }
};
