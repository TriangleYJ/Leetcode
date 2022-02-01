/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // not increasing list!
        // 나보다 큰 방향으로 binary search를 하자. 
        // 최대 최소 정리

        int s = nums.size();
        // 1. handle side case
        if(nums.size() == 1 || nums.at(0) > nums.at(1)) return 0;
        if(nums.at(s-1) > nums.at(s-2)) return s-1;

        // 2. others (s > 3)
        int left = 1;
        int right = s - 2;
        while(1){
            int mid = (left + right) / 2;
            int pv = nums.at(mid-1);
            int v = nums.at(mid);
            int nv = nums.at(mid+1);
            
            if(v > pv && v > nv) return mid;
            if(pv > v) right = mid - 1;
            else if(nv > v) left = mid + 1;
        }
    }
};
// @lc code=end

