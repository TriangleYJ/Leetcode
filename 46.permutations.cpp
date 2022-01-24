/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int taken[7] = {0};
        return permuteWithTaken(nums, taken);
    }

    vector<vector<int>> permuteWithTaken(vector<int>& nums, int taken[10]){
        vector<vector<int>> res;
        int loop_cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(taken[i]) continue;
            else loop_cnt++;
            taken[i] = 1;
            vector<vector<int>> p = permuteWithTaken(nums, taken);
            for (int j = 0; j < p.size(); j++) p.at(j).push_back(nums.at(i));
            res.insert(res.end(), p.begin(), p.end());
            taken[i] = 0;
        }
        if(loop_cnt == 0) return {{}};
        return res;
    }
};
// @lc code=end

