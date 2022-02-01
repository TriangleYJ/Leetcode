/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        
        int left = 0;
        int right = nums.size() - 1;
        vector<int> result;

        while(left < right){
            int mid = (left + right)/2;
            if(nums.at(mid) >= target) right = mid;
            else if(nums.at(mid) < target) left = mid+1;
        }

        if(nums.at(left) != target) return {-1, -1};

        result.push_back(left);

        left = 0;
        right = nums.size() - 1;

        while(left < right){
            int mid = (left + right)/2 + (left + right) % 2;
            if(nums.at(mid) > target) right = mid-1;
            else if(nums.at(mid) <= target) left = mid;
        }
        result.push_back(left);

        return result;
    }
};
// @lc code=end

