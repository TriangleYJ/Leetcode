/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int MAX = 1000000;
        int tmp = nums.at(0), l = 0, r = 0, mmin = MAX;
        while(1){
            if(tmp >= target){
                mmin = min(mmin, r-l+1);
                if(l == nums.size() - 1) break;
                if(r == l){
                    r++;
                    l++;
                    tmp = nums.at(l);
                } else tmp -= nums.at(l++);
            } else {
                if(r == nums.size() - 1) break;
                tmp += nums.at(++r);
            }
        }
        if(mmin == MAX) return 0;
        return mmin;
    }
};
// @lc code=end

