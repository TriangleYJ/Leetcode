/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
   private:
    int cnt[21] = {0};
    int tmp[10] = {0};
    vector<int> unique;
    vector<vector<int>> results;

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for (int i : nums) {
            if (cnt[i + 10]++ == 0) unique.push_back(i);
        }
        putSubset(0);
        return results;
    }

    void putSubset(int idx) {
        if (idx == unique.size()) {
            vector<int> elem;
            for (int i = 0; i < unique.size(); i++)
                for (int j = 0; j < tmp[i]; j++) elem.push_back(unique.at(i));
            results.push_back(elem);
            return;
        }
        for (int i = 0; i <= cnt[unique.at(idx) + 10]; i++) {
            tmp[idx] = i;
            putSubset(idx + 1);
        }
    }
};
// @lc code=end
