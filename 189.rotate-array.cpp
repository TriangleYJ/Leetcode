/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret(n);
        for(int i = 0; i < n; i++){
            int shift_pos = i + k;
            shift_pos = shift_pos % n;
            ret.at(shift_pos) = nums.at(i);
        }
        
        nums = ret;
    }
};
// @lc code=end

