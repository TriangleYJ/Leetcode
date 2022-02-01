/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
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
            flip = right;
        } else flip = 0;

        //2. binary search with flip point: O(logn)
        left = 0;
        right = nums.size() - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(get(mid, flip, nums) < target) left = mid+1;
            else if(get(mid, flip, nums) >= target) right = mid;
        }
        if(get(left, flip, nums) != target) return -1;
        return (left + flip) % nums.size();
    }

    int get(int idx, int flip_point, vector<int>& nums){
        return nums.at((idx + flip_point) % nums.size());
    }
};
// @lc code=end

