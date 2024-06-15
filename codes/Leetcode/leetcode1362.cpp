class Solution {
public:
    int findDivisors(long long num) {
        int start = sqrt(num);
        for (int i = start; i >= 1; i--) {
            if (num % i == 0) {
                return i;
            }
        }
        return 1;
    }
    vector<int> closestDivisors(int num) {
        int addone = findDivisors(1LL + num);
        int addtwo = findDivisors(2LL + num);
        
        int disone = (1LL + num) / addone - addone;
        int distwo = (2LL + num) / addtwo - addtwo;
        std::vector<int> ans;
        if (disone < distwo) {
            ans.emplace_back(addone);
            ans.emplace_back(addone + disone);
        } else {
            ans.emplace_back(addtwo);
            ans.emplace_back(addtwo + distwo);
        }
        return ans;
    }
};
