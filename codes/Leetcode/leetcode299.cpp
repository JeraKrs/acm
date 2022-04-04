class Solution {
public:
    string getHint(string secret, string guess) {
        int secret_cows[10];
        int guess_cows[10];
        memset(secret_cows, 0, sizeof(secret_cows));
        memset(guess_cows, 0, sizeof(guess_cows));

        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            } else {
                secret_cows[secret[i] - '0']++;
                guess_cows[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; ++i) {
            cows += min(secret_cows[i], guess_cows[i]);
        }
        string ans;
        ans += to_string(bulls);
        ans += 'A';
        ans += to_string(cows);
        ans += 'B';
        return ans;
    }
};
