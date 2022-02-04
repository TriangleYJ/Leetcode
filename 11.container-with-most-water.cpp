/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int s = height.size();
        int l = 0;
        int r = s-1;
        int mmax = 0;
        while(l < r){
            int lv = height.at(l);
            int rv = height.at(r);
            int val = (r-l) * min(lv, rv);
            if(mmax < val) mmax = val;
            if(rv < lv) while(r >= 0 && height.at(r) <= rv) r--;
            else while(l < s && height.at(l) <= lv) l++;
        }
        return mmax;
    }
};
// @lc code=end
