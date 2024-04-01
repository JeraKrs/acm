class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = 1, L = area;
        for (int i = 2; i * i <= area; ++i) {
            if (area % i == 0) {
                W = i;
                L = area / i;
            }
        }
        return {L, W};
    }
};
