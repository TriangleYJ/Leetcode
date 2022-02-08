/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int s = nums.size();
        for (int i = 0; i < 1<<s; i++) {
            vector<int> tmp;
            for(int j = 0; j < s; j++){
                int jth_bit = (i >> j) & 1;
                if(jth_bit) tmp.push_back(nums.at(j));
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

