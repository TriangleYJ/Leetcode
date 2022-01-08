/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(target <= nums.at(0)) return 0;
        else if(target > nums.at(n-1)) return n;
        else return search(nums, target, 1, n-1);
    }
    
    // 1 3 5 6
    //  | | | 
    //  2 5  
    int search(vector<int>& nums, int target, int sx, int ex){
        int l = (ex + sx) / 2;
        int v = nums.at(l-1);
        int next = nums.at(l);
        if(target <= next && target > v) return l;
        else if(target > next) return search(nums, target, l+1, ex);
        else return search(nums, target, sx, l-1);
    }  

};
// @lc code=end

