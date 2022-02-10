/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
private:
    vector<int> unique;
    int cnt[21] = {0};
    vector<int> tmp;
    vector<vector<int>> result;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i: nums){
            if(cnt[i+10]++ == 0) unique.push_back(i);
        }
        permuteUniqueStep();
        return result;
    }

    void permuteUniqueStep(){
        bool exists = false;
        for(int num: unique){
            if(cnt[num+10] > 0){
                exists = true;
                tmp.push_back(num);
                cnt[num+10]--;
                permuteUniqueStep();
                tmp.pop_back();
                cnt[num+10]++;
            }
        }
        if(!exists) result.push_back(tmp);
    }
};
// @lc code=end

