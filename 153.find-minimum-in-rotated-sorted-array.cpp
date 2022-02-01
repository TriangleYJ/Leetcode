/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int flip = -1;
        int left = 0;
        int right = nums.size() - 1;
        //1. find flip point: O(logn)
        if(nums.at(left) > nums.at(right)){
            while(left + 1 != right){
                int mid = (left + right) / 2;
                if(nums.at(mid) > nums.at(left)) left = mid;
                if(nums.at(mid) < nums.at(right)) right = mid;
            }
            return nums.at(right);
        } else return nums.at(0);
    }
};
// @lc code=end

