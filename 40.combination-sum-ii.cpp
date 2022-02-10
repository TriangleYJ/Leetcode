/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
   private:
    vector<int> tmp;
    vector<int> c;
    vector<vector<int>> results;
    int t;

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        c = candidates, t = target;
        step(0, 0);
        return results;
    }

    void step(int val, int last_num) {
        if (val == t) {
            results.push_back(tmp);
        }
        if (val < t) {
            for (int i = last_num; i < c.size(); i++) {
                tmp.push_back(c.at(i));
                step(val + c.at(i), i + 1);
                tmp.pop_back();
                while (i < c.size() - 1 && c.at(i) == c.at(i + 1)) i++;
            }
        }
    }
};
// @lc code=end
