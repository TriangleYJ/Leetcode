/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp(nums.size());
        int cnt[7] = {0};
        permuteCnt(nums, result, tmp, cnt, 0);

        return result;
    }

    void permuteCnt(vector<int>& nums, vector<vector<int>>& result, vector<int>& tmp, int occ[7], int cnt){
        if(cnt == nums.size()) result.push_back(tmp);
        for (int i = 0; i < nums.size(); i++)
        {
            if(occ[i]) continue;
            occ[i] = 1;
            tmp.at(cnt) = nums[i];
            permuteCnt(nums, result, tmp, occ, cnt+1);
            occ[i] = 0;
        }
    }

};
// @lc code=end

