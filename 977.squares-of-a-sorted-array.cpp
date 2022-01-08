/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> snums;
        for(int i : nums){
            snums.push_back(i*i);
        }
        sort(snums.begin(), snums.end());
        return snums;
        
    }
};
// @lc code=end

