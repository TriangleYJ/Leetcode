/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        // com(n, k)
        // com(n+1, k) = com(n, k) + {com(n, k-1), n+1}
        // com(n, 1) = [[1], [2], [3], ...]
        // memoization?
        if (k == 1) {
            vector<vector<int>> mvec;
            for (int i = 0; i < n; i++) {
                mvec.push_back({i + 1});
            }
            return mvec;
        }
        if (k == n) {
            vector<int> mvec;
            for (int i = 0; i < n; i++) {
                mvec.push_back(i + 1);
            }
            return {mvec};
        }
        vector<vector<int>> c1 = combine(n - 1, k);
        vector<vector<int>> c2 = combine(n - 1, k - 1);
        for (int i = 0; i < c2.size(); i++) {
            c2.at(i).push_back(n);
        }

        c1.insert(c1.end(), c2.begin(), c2.end());
        return c1;
    }
};
// @lc code=end
