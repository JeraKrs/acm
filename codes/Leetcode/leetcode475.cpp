class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());

        function<bool(int)> judge = [&](int range) {
            int mov = 0;
            for (auto heater : heaters) {
                int l = heater - range;
                int r = heater + range;
                while (mov < houses.size() && houses[mov] >= l && houses[mov] <= r) mov++;
            }
            return mov >= houses.size();

        };
        int l = -1, r = 1e9;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (judge(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
};
