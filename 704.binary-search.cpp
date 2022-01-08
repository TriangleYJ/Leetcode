/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size()-1);
    }
    
    int search(vector<int>& nums, int target, int sx, int ex){
        int l = (ex + sx) / 2;
        int v = nums.at(l);
        if(v == target) return l;
        else if(sx == ex) return -1;
        else if (v > target) return search(nums, target, sx, l);
        else return search(nums, target, l+1, ex);
    }
};
// @lc code=end

