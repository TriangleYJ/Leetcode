/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
private:
    int result[401] = {-1};
public:
    int rob(vector<int>& nums) {
        int s = nums.size();
        if(s == 1) result[0] = nums[0];
        if(s >= 2) result[1] = max(nums[1], nums[0]);
        if(s >= 3) result[2] = max(nums[1], nums[0] + nums[2]);
        if(s >= 4) for(int i = 3; i < s; i++) result[i] = max(max(result[i-3] + nums[i], result[i-2] + nums[i]), result[i-1]);
        return result[s-1];
        // f(defg) = max(f(de) + g, f(d) + g, f(def))
    }
};
// @lc code=end

