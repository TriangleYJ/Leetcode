/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
   public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int i = 0; i < min(n - 1, m - 1); i++) {
            ans *= (m + n - 2 - i);
            ans /= (i + 1);
        }
        return ans;
    }
};
// @lc code=end
