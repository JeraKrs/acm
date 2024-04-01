class Solution {
public:
    bool isRobotBounded(string instructions) {
        const int dir[] = {0, 1, 0, -1, 0};

        int x = 0, y = 0, d = 0;
        for (int k = 0; k < 4; ++k) {
            for (int i = 0; i < instructions.size(); ++i) {
                if (instructions[i] == 'G') {
                    x += dir[d];
                    y += dir[d+1];
                } else if (instructions[i] == 'L') {
                    d = (d - 1 + 4) % 4;
                } else if (instructions[i] == 'R') {
                    d = (d + 1) % 4;
                }
            }
            if (x == 0 && y == 0) return true;
        }
        return false;
    }
};
