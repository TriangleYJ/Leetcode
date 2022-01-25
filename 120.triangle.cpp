/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // f(depth, index) = max(f(depth-1, index-1) + v, f(depth-1, index) + v)
        int s = triangle.size();
        if(s == 1) return triangle.at(0).at(0);
        for (int depth = 1; depth < s; depth++) {
            for (int idx = 0; idx <= depth; idx++) {
                int val = triangle.at(depth).at(idx);
                if(idx == 0) triangle.at(depth).at(idx) = triangle.at(depth - 1).at(idx) + val;
                else if(idx == depth) triangle.at(depth).at(idx) = triangle.at(depth - 1).at(idx - 1) + val;
                else triangle.at(depth).at(idx) = min(triangle.at(depth - 1).at(idx - 1), triangle.at(depth - 1).at(idx)) + val;
            }
        }

        return *min_element(triangle.at(s-1).begin(), triangle.at(s-1).end());
    }
};
// @lc code=end
