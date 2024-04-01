class Solution {
public:
    int flipLights(int n, int presses) {
        const unsigned int op[] = {63, 42, 21, 9};
        std::queue<int> que;
        unsigned int bit = (1<<(std::min(6,n))) - 1;
        std::vector<int> records;
        records.resize(bit+1, 0);
        que.push(0);

        for (int i = 1; i <= presses; ++i) {
            int s = que.size();
            while (s--) {
                unsigned int x = que.front();
                que.pop();
                for (int j = 0; j < 4; ++j) {
                    unsigned int y = (x ^ op[j]) & bit;
                    if (records[y] != i) {
                        records[y] = i;
                        que.push(y);
                    }
                }
            }
        }

        return que.size();
    }
};
