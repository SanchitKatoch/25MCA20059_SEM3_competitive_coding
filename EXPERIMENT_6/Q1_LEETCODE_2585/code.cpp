https://leetcode.com/problems/number-of-ways-to-earn-points/submissions/2194412900/


class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        const int MOD = 1e9 + 7;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (auto& type : types) {
            int count = type[0];
            int marks = type[1];

            vector<int> next(target + 1, 0);

            for (int j = 0; j <= target; j++) {
                for (int k = 0; k <= count && k * marks <= j; k++) {
                    next[j] = (next[j] + dp[j - k * marks]) % MOD;
                }
            }

            dp = next;
        }

        return dp[target];
    }
};
