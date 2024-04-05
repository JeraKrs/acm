class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        
        int n = flowers.size();
        std::sort(flowers.begin(), flowers.end());
        int minimum = flowers[0];
        if (minimum >= target) return 1LL * n * full;

        std::vector<long long> needs;
        needs.resize(n + 1, 0);
        for (int i = n-1; i >= 0; --i) {
            needs[i] = needs[i+1] +  std::max(target - flowers[i], 0);
        }

        long long ans = 0;
        int full_mov = 0, partial_mov = 0;
        for (int i = minimum; i <= target; ++i) {
            while (partial_mov < n && flowers[partial_mov] < i) partial_mov++;
            newFlowers -= partial_mov;
            if (newFlowers < 0) break;
            full_mov = std::max(full_mov, partial_mov);
            while (full_mov < n && needs[full_mov] > newFlowers) full_mov++;

            long long full_bias = 0;
            if (i < target) {
                long long res_flowers = newFlowers - needs[full_mov];
                full_bias = res_flowers / (target - i);
            }
            long long full_cnt = n - full_mov + std::min((long long)partial_mov - 1, full_bias);
            long long tmp = 1LL * full_cnt * full + 1LL * i * partial;
            if (i == target) tmp = 1LL * n * full;
            ans = std::max(ans, tmp);
        }
        return ans;
    }
};
