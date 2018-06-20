class Solution {
	public:
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			int n = gas.size();
			int sumOfGas = 0, sumOfCost = 0;
			for (int i = 0; i < n; i++) {
				sumOfGas += gas[i];
				sumOfCost += cost[i];
			}
			if (sumOfGas < sumOfCost) return -1;

			int ans = 0, pos = -1, sum = 0;
			for (int i = 0; i < n; i++) {
				sum += cost[i] - gas[i];
				if (pos == -1 || sum > ans) {
					pos = i;
					ans = sum;
				}
				sum = max(sum, 0);
			}

			ans = sumOfGas - sumOfCost + ans;
			sum = 0;
			for (int i = n-1; i >= 0; i--) {
				sum += gas[i] - cost[i];
				if (pos == -1 || sum > ans) {
					pos = i-1;
					ans = sum;
				}
				sum = max(sum, 0);
			}

			return (pos + 1) % n;
		}
};
