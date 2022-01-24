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
        vector<int> builder(nums.size());
        int number_map[7] = {0};
        permuteStep(nums, result, builder, number_map, 0);

        return result;
    }

    void permuteStep(vector<int>& nums, vector<vector<int>>& result, vector<int>& builder, int n_map[7], int step){
        if(step == nums.size()) result.push_back(builder);
        for (int i = 0; i < nums.size(); i++)
        {
            if(n_map[i]) continue;
            n_map[i] = 1;
            builder.at(step) = nums[i];
            permuteStep(nums, result, builder, n_map, step+1);
            n_map[i] = 0;
        }
    }

};
// @lc code=end

