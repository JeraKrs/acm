class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i]) continue;
            bool left_check = (i == 0 || flowerbed[i-1] == 0);
            bool right_check = (i + 1 == flowerbed.size() || flowerbed[i+1] == 0);
            if (left_check && right_check) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};
