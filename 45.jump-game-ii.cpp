/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
   private:
    const int N = 1 << 30;

   public:
    int jump(vector<int>& nums) {
        int s = nums.size();
        nums.at(s - 1) = 0;
        for (int i = s - 2; i >= 0; i--) {
            int val_i = nums.at(i);
            int mmin = N;
            for (int j = 1; j <= val_i; j++) {
                if(i + j >= s) break;
                int val_ij = nums.at(i + j);
                if (val_ij != -1 && mmin > val_ij) mmin = val_ij + 1;
            }
            nums.at(i) = (mmin == N ? -1 : mmin);
        }
        return nums.at(0);
    }
};
// @lc code=end
